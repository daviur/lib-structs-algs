#ifndef dtal_list_h
#define dtal_list_h

#include <stdlib.h>

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *dtal_list_create();
void dtal_list_destroy(List *list);
void dtal_list_clear(List *list);
void dtal_list_clear_destroy(List *list);

#define dtal_list_count(A) (A->count)
#define dtal_list_first(A) (A->first != NULL ? (A)->first->value : NULL)
#define dtal_list_last(A) (A->last != NULL ? (A)->last->value : NULL)

void dtal_list_push(List *list, void *value);
void *dtal_list_pop(List *list);

void dtal_list_push_left(List *list, void *value);
void *dtal_list_pop_left(List *list);

void *dtal_list_remove(List *list, ListNode *node);

#define LIST_FOREACH(L, S, M, V) \
    ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
