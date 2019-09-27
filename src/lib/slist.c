#include <stdlib.h>

#include "slist.h"

struct SLinkedListNode {
    struct SLinkedListNode *next;
    void *value;
};

struct SLinkedList {
    int count;
    SLinkedListNode head;
    SLinkedListNode tail;
};

SLinkedList dtal_slist_create() {
    return calloc(1, sizeof(SLinkedList));
}

void dtal_slist_clear(SLinkedList slist) {
    while (!dtal_slist_is_empty(slist)) {
        dtal_slist_pop(slist);
    }
}

void dtal_slist_destroy(SLinkedList *slist) {
    dtal_slist_clear(*slist);
    free(*slist);
    *slist = NULL;
}

inline int dtal_slist_count(SLinkedList list) {
    return list->count;
}

inline inline void *dtal_slist_head(SLinkedList slist) {
    return slist->head != NULL ? (slist)->head->value : NULL;
}

inline void *dtal_slist_tail(SLinkedList slist) {
    return slist->tail != NULL ? (slist)->tail->value : NULL;
}

inline int dtal_slist_is_empty(SLinkedList slist) {
    return slist->count == 0;
}

void dtal_slist_push(SLinkedList slist, void *value) {
    SLinkedListNode node = calloc(1, sizeof(SLinkedListNode));
    node->value = value;

    if (slist->head == NULL) {
        slist->head = node;
    } else {
        slist->tail->next = node;
    }

    slist->tail = node;
    slist->count++;
}

void dtal_slist_push_left(SLinkedList slist, void *value) {
    SLinkedListNode node = calloc(1, sizeof(SLinkedListNode));
    node->value = value;

    if (slist->tail == NULL) {
        slist->tail = node;
    } else {
        node->next = slist->head;
    }

    slist->head = node;
    slist->count++;
}

void *dtal_slist_remove(SLinkedList slist, SLinkedListNode node) {
    SLinkedListNode prev;
    LIST_FOREACH(slist, curr) {
        if (curr == node) {
            break;
        }
        prev = curr;
    }

    if (node == slist->head && node == slist->tail) {
        slist->head = NULL;
        slist->tail = NULL;
    } else if (node == slist->head) {
        slist->head = node->next;
    } else if (node == slist->tail) {
        slist->tail = prev;
        slist->tail->next = NULL;
    } else {
        prev->next = node->next;
    }

    slist->count--;
    void *value = node->value;
    free(node);
    return value;
}

void *dtal_slist_pop(SLinkedList slist) {
    SLinkedListNode node = slist->tail;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
}

void *dtal_slist_pop_left(SLinkedList slist) {
    SLinkedListNode node = slist->head;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
}
