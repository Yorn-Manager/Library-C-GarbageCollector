/*
** EPITECH PROJECT, 2024
** Library-C-GarbageCollector
** File description:
** f_garbage_collector_utils
*/

#include "f_garbage_collector.h"

static void write_nbr(size_t n)
{
    char c = n % 10 + '0';

    if (n >= 10) {
        write_nbr(n / 10);
        write(1, &c, 1);
    }
    if (n < 10)
        write(1, &c, 1);
}

void _fgc_free_pointed_data(void *data)
{
    f_free(*(void **)data);
}

void _fgc_display_real_allocations(void)
{
    size_t nb_allocs = 0;
    size_t size_allocs = fgc_get_allocated_size(&nb_allocs);

    write(1, "==\033[2mDEBUG\033[0m== Allocated ", 29);
    write_nbr(size_allocs);
    write(1, " bytes in ", 10);
    write_nbr(nb_allocs);
    write(1, " allocations.\n", 13);
}