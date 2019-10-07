#include <stdlib.h>

#include "helper.h"
#include "dbg.h"
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
    DLinkedList dlist = STRUCT_CALLOC(DLinkedList);
    check_mem(dlist);
    return dlist;
error:
    return NULL;
}

int dtal_dlist_clear(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    while (!dtal_dlist_is_empty(dlist)) {
        dtal_dlist_pop(dlist);
    }
error:
    return ERR;
}

int dtal_dlist_destroy(DLinkedList *dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    dtal_dlist_clear(*dlist);
    free(*dlist);
    *dlist = NULL;
error:
    return ERR;
}

inline int dtal_dlist_count(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    return dlist->count;
error:
    return ERR;
}

inline void *dtal_dlist_head(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    return dlist->head != NULL ? (dlist)->head->value : NULL;
error:
    return NULL;
}

inline void *dtal_dlist_tail(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    return dlist->tail != NULL ? (dlist)->tail->value : NULL;
error:
    return NULL;
}

inline int dtal_dlist_is_empty(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    return dlist->count == 0;
error:
    return ERR;
}

int dtal_dlist_push(DLinkedList dlist, void *value) {
    check(dlist != NULL, "Invalid DLinkedList");
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
error:
    return ERR;
}

int dtal_dlist_push_left(DLinkedList dlist, void *value) {
    check(dlist != NULL, "Invalid DLinkedList");
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
error:
    return ERR;
}

void *dtal_dlist_remove(DLinkedList dlist, DLinkedListNode node) {
    check(dlist != NULL, "Invalid DLinkedList");
    check(node != NULL, "Invalid DLinkedListNode");
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
error:
    return NULL;
}

void *dtal_dlist_pop(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    DLinkedListNode node = dlist->tail;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
error:
    return NULL;
}

void *dtal_dlist_pop_left(DLinkedList dlist) {
    check(dlist != NULL, "Invalid DLinkedList");
    DLinkedListNode node = dlist->head;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
error:
    return NULL;
}
