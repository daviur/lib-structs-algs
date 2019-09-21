#ifndef dtal_slist_h
#define dtal_slist_h

#include <stdlib.h>

typedef struct SLinkedListNode {
    struct SLinkedListNode *next;
    void *value;
} SLinkedListNode;

typedef struct SLinkedList {
    int count;
    SLinkedListNode *head;
    SLinkedListNode *tail;
} SLinkedList;

SLinkedList *dtal_slist_create();
void dtal_slist_destroy(SLinkedList *slist);
void dtal_slist_clear(SLinkedList *slist);
void dtal_slist_clear_destroy(SLinkedList *slist);

#define dtal_slist_count(A) (A->count)
#define dtal_slist_head(A) (A->head != NULL ? (A)->head->value : NULL)
#define dtal_slist_tail(A) (A->tail != NULL ? (A)->tail->value : NULL)

void dtal_slist_push(SLinkedList *slist, void *value);
void *dtal_slist_pop(SLinkedList *slist);

void dtal_slist_push_left(SLinkedList *slist, void *value);
void *dtal_slist_pop_left(SLinkedList *slist);

void *dtal_slist_remove(SLinkedList *slist, SLinkedListNode *node);

#define LIST_FOREACH(L, V) \
    SLinkedListNode *_node = NULL;\
    SLinkedListNode *V = NULL;\
    for(V = _node = L->head; _node != NULL; V = _node = _node->next)

#endif
