#include <stdlib.h>

#include "helper.h"
#include "dlist.h"

struct DLinkedList {
    int count;
    DLinkedListNode head;
    DLinkedListNode tail;
};

struct DLinkedListNode {
    struct DLinkedListNode *next;
    struct DLinkedListNode *prev;
    void *value;
};

DLinkedList dtal_dlist_create() {
    return STRUCT_CALLOC(DLinkedList);
}

void dtal_dlist_clear(DLinkedList dlist) {
    while (!dtal_dlist_is_empty(dlist)) {
        dtal_dlist_pop(dlist);
    }
}

void dtal_dlist_destroy(DLinkedList *dlist) {
    dtal_dlist_clear(*dlist);
    free(*dlist);
    *dlist = NULL;
}

inline int dtal_dlist_count(DLinkedList dlist) {
    return dlist->count;
}

inline void *dtal_dlist_head(DLinkedList dlist) {
    return dlist->head != NULL ? (dlist)->head->value : NULL;
}

inline void *dtal_dlist_tail(DLinkedList dlist) {
    return dlist->tail != NULL ? (dlist)->tail->value : NULL;
}

inline int dtal_dlist_is_empty(DLinkedList dlist) {
    return dlist->count == 0;
}

void dtal_dlist_push(DLinkedList dlist, void *value) {
    DLinkedListNode node = STRUCT_CALLOC(DLinkedListNode);
    node->value = value;

    if (dlist->head == NULL) {
        dlist->head = node;
    } else {
        dlist->tail->next = node;
        node->prev = dlist->tail;
    }

    dlist->tail = node;
    dlist->count++;
}

void dtal_dlist_push_left(DLinkedList dlist, void *value) {
    DLinkedListNode node = STRUCT_CALLOC(DLinkedListNode);
    node->value = value;

    if (dlist->tail == NULL) {
        dlist->tail = node;
    } else {
        dlist->head->prev = node;
        node->next = dlist->head;
    }

    dlist->head = node;
    dlist->count++;
}

void *dtal_dlist_remove(DLinkedList dlist, DLinkedListNode node) {
    if (node == dlist->head && node == dlist->tail) {
        dlist->head = NULL;
        dlist->tail = NULL;
    } else if (node == dlist->head) {
        dlist->head = node->next;
        dlist->head->prev = NULL;
    } else if (node == dlist->tail) {
        dlist->tail = node->prev;
        dlist->tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    dlist->count--;
    void *value = node->value;
    free(node);
    return value;
}

void *dtal_dlist_pop(DLinkedList dlist) {
    DLinkedListNode node = dlist->tail;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
}

void *dtal_dlist_pop_left(DLinkedList dlist) {
    DLinkedListNode node = dlist->head;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
}
