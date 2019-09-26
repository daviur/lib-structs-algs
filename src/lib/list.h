#ifndef dtal_list_h
#define dtal_list_h

#include <stdlib.h>

typedef struct List {
    int count;
    int size;
    void **array;
} List;

List *dtal_list_create(void);
List *dtal_list_create_sized(int size);
void dtal_list_destroy(List *list);
void dtal_list_clear(List *list);
void dtal_list_clear_destroy(List *list);

#define dtal_list_count(A) (A->count)
#define dtal_list_size(A) (A->size)
#define dtal_list_head(A) ((A->count > 0) ? (A)->array[0] : NULL)
#define dtal_list_tail(A) ((A->count > 0) ? (A)->array[(A)->count - 1] : NULL)

void dtal_list_push(List *list, void *value);
void dtal_list_push_left(List *list, void *value);
void *dtal_list_pop(List *list);
void *dtal_list_pop_left(List *list);
void dtal_list_insert(List *list, int index, void *value);
void *dtal_list_remove(List *list, int index);

#define LIST_FOREACH(L, C) \
    void *C = NULL; \
    for (int i = 0; i < L->count; i++) { \
        C = L->array[i];

#endif

