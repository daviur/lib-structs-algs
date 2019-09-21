#ifndef dtal_dlist_h
#define dtal_dlist_h

#include <stdlib.h>

typedef struct DLinkedListNode {
    struct DLinkedListNode *next;
    struct DLinkedListNode *prev;
    void *value;
} DLinkedListNode;

typedef struct DLinkedList {
    int count;
    DLinkedListNode *head;
    DLinkedListNode *tail;
} DLinkedList;

DLinkedList *dtal_dlist_create();
void dtal_dlist_destroy(DLinkedList *dlist);
void dtal_dlist_clear(DLinkedList *dlist);
void dtal_dlist_clear_destroy(DLinkedList *dlist);

#define dtal_dlist_count(A) (A->count)
#define dtal_dlist_head(A) (A->head != NULL ? (A)->head->value : NULL)
#define dtal_dlist_tail(A) (A->tail != NULL ? (A)->tail->value : NULL)

void dtal_dlist_push(DLinkedList *dlist, void *value);
void *dtal_dlist_pop(DLinkedList *dlist);

void dtal_dlist_push_left(DLinkedList *dlist, void *value);
void *dtal_dlist_pop_left(DLinkedList *dlist);

void *dtal_dlist_remove(DLinkedList *dlist, DLinkedListNode *node);

#define LIST_FOREACH(L, S, M, V) \
    DLinkedListNode *_node = NULL;\
    DLinkedListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
