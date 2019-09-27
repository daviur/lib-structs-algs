#ifndef dtal_dlist_h
#define dtal_dlist_h

typedef struct DLinkedListNode * DLinkedListNode;
typedef struct DLinkedList * DLinkedList;

DLinkedList dtal_dlist_create();
void dtal_dlist_clear(DLinkedList dlist);
void dtal_dlist_destroy(DLinkedList *dlist);

int dtal_dlist_count(DLinkedList dlist);
void *dtal_dlist_head(DLinkedList dlist);
void *dtal_dlist_tail(DLinkedList dlist);
int dtal_dlist_is_empty(DLinkedList dlist);

void dtal_dlist_push(DLinkedList dlist, void *value);
void *dtal_dlist_pop(DLinkedList dlist);

void dtal_dlist_push_left(DLinkedList dlist, void *value);
void *dtal_dlist_pop_left(DLinkedList dlist);

void *dtal_dlist_remove(DLinkedList dlist, DLinkedListNode node);

#define LIST_FOREACH(L, S, M, V) \
    DLinkedListNode *_node = NULL;\
    DLinkedListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
