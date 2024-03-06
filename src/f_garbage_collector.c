/*
** EPITECH PROJECT, 2024
** Library-C-GarbageCollector
** File description:
** garbage_collector
*/

#include "f_garbage_collector.h"

static garbage_list garbage_collector_reference;

static garbage_list fgcl_create_new(void *ptr)
{
    garbage_list new = (garbage_list)malloc(sizeof(_garbage_list));

    new->prev = NULL;
    new->ptr = ptr;
    new->next = NULL;
    return new;
}

static void fgcl_add(garbage_list new)
{
    garbage_list current = garbage_collector_reference;

    if (!current)
        return;
    for (; current->next; current = current->next);
    current->next = new;
    new->prev = current;
}

void fgc_cleanup(void)
{
    garbage_list current = garbage_collector_reference;

    if (!garbage_collector_reference)
        return;
    for (; current->prev; current = current->prev);
    for (; current->next; current = current->next) {
        if (!current->prev)
            continue;
        free(current->prev->ptr);
        free(current->prev);
        current->prev = NULL;
    }
    if (current->prev) {
        free(current->prev->ptr);
        free(current->prev);
    }
    free(current->ptr);
    free(current);
    garbage_collector_reference = NULL;
}

void *fgc_malloc(size_t size)
{
    void *obj = malloc(size);

    if (!garbage_collector_reference)
        garbage_collector_reference = fgcl_create_new(obj);
    else
        fgcl_add(fgcl_create_new(obj));
    return obj;
}

void fgc_free(void *ptr)
{
    garbage_list current = garbage_collector_reference;

    if (!current)
        return;
    for (; current->prev; current = current->prev);
    for (; current; current = current->next) {
        if (current->ptr != ptr)
            continue;
        free(current->ptr);
        if (current == garbage_collector_reference)
            garbage_collector_reference = current->prev ?
                current->prev : current->next;
        if (current->prev)
            current->prev->next = current->next;
        if (current->next)
            current->next->prev = current->prev;
        free(current);
        return;
    }
}