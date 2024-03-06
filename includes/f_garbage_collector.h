/*
** EPITECH PROJECT, 2024
** Library-C-GarbageCollector
** File description:
** f_garbage_collector
*/

#ifndef INCLUDED_F_GARBAGE_COLLECTOR_H
    #define INCLUDED_F_GARBAGE_COLLECTOR_H

    #include <stdlib.h>

typedef struct _garbage_list {
    struct _garbage_list *prev;
    void *ptr;
    struct _garbage_list *next;
} _garbage_list;
typedef _garbage_list* garbage_list;


#if (defined(__GNUC__) && defined(FGC_SELF_CLEAN))
__attribute__((destructor)) void fgc_cleanup(void);
#elif (defined(FGC_SELF_CLEAN))
    #error "Can not use self clean features while not in GNU !"
#else
void fgc_cleanup(void);
#endif

void *fgc_malloc(size_t size);
void fgc_free(void *ptr);

    #define USE_CUSTOM_MALLOC
    #define f_malloc(size) fgc_malloc(size)
    #define f_free(ptr) fgc_free(ptr)

#endif
