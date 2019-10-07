#ifndef dtal_slist_h
#define dtal_slist_h

typedef struct SLinkedListNode * SLinkedListNode;
typedef struct SLinkedList * SLinkedList;

SLinkedList dtal_slist_create();
void dtal_slist_clear(SLinkedList slist);
void dtal_slist_destroy(SLinkedList *slist);

int dtal_slist_count(SLinkedList list);
void *dtal_slist_head(SLinkedList slist);
void *dtal_slist_tail(SLinkedList slist);
int dtal_slist_is_empty(SLinkedList slist);

void dtal_slist_push(SLinkedList slist, void *value);
void *dtal_slist_pop(SLinkedList slist);

void dtal_slist_push_left(SLinkedList slist, void *value);
void *dtal_slist_pop_left(SLinkedList slist);

void *dtal_slist_remove(SLinkedList slist, SLinkedListNode node);

#define LIST_FOREACH(L, V) \
    SLinkedListNode _node = NULL;\
    SLinkedListNode V = NULL;\
    for(V = _node = L->head; _node != NULL; V = _node = _node->next)

#endif
