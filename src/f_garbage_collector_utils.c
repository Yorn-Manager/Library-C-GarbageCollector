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
    size_t ttl_nb_allocs = 0;
    size_t ttl_size_allocs = 0;
    size_t nb_allocs = 0;
    size_t size_allocs = fgc_get_allocated_size(&nb_allocs, &ttl_nb_allocs,
        &ttl_size_allocs);

    write(1, "==\033[2mDEBUG\033[0m==   total heap usage: ", 38);
    write_nbr(ttl_nb_allocs);
    write(1, " allocs, ", 9);
    write_nbr(ttl_size_allocs);
    write(1, " bytes allocated\n", 17);
    write(1, "==\033[2mDEBUG\033[0m== current heap usage: ", 38);
    write_nbr(nb_allocs);
    write(1, " allocs, ", 9);
    write_nbr(size_allocs);
    write(1, " bytes allocated\n", 17);
}