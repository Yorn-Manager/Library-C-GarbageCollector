/*
** EPITECH PROJECT, 2024
** Library-C-GarbageCollector
** File description:
** f_garbage_collector
*/

#ifndef INCLUDED_F_GARBAGE_COLLECTOR_H
    #define INCLUDED_F_GARBAGE_COLLECTOR_H

    #include <stdlib.h>
    #include <unistd.h>

typedef struct _garbage_list {
    struct _garbage_list *prev;
    void *ptr;
    size_t size;
    struct _garbage_list *next;
} _garbage_list;
typedef _garbage_list* garbage_list;

void *fgc_malloc(size_t size);
void fgc_free(void *ptr);
size_t fgc_get_allocated_size(size_t *nb_allocations);
void fgc_cleanup(void);

void _fgc_free_pointed_data(void *data);
void _fgc_display_real_allocations(void);

    #if (defined(__GNUC__) && defined(FGC_SELF_CLEAN))
        void __attribute__((destructor)) _fgc_cleanup(void) {fgc_cleanup();};
    #elif (defined(FGC_SELF_CLEAN))
        #error "Can not use self clean features while not in GNU !"
    #endif

    #if __has_include(<valgrind/valgrind.h>)
        #include <valgrind/valgrind.h>
    #else
        #define RUNNING_ON_VALGRIND 0
    #endif

    #define USE_CUSTOM_MALLOC
    #define f_malloc(size) fgc_malloc(size)
    #define f_free(ptr) fgc_free(ptr)

    #if defined(__GNUC__)
        #define FREE __attribute__((cleanup(_fgc_free_pointed_data)))
    #endif

#endif
