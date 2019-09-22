#ifndef dtal_list_h
#define dtal_list_h

#include <stdlib.h>

typedef struct List {
    int count;
    int size;
    void **array;
} List;

List *dtal_list_create();
void dtal_list_destroy(List *list);
void dtal_list_clear(List *list);
void dtal_list_clear_destroy(List *list);

#define dtal_list_count(A) (A->count)
#define dtal_list_head(A) (A->count > 0) ? (A)->array[0] : NULL)
#define dtal_list_tail(A) (A->count > 0) ? (A)->array[count - 1] : NULL)

void dtal_list_push(List *list, void *value);
void *dtal_list_pop(List *list);

#define LIST_FOREACH(L, S, M, V) \
    ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif

