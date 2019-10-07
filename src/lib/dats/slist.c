#include <stdlib.h>

#include "helper.h"
#include "dbg.h"
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
    SLinkedList slist = STRUCT_CALLOC(SLinkedList);
    check_mem(slist);
    return slist;
error:
    return NULL;
}

int dtal_slist_clear(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    while (!dtal_slist_is_empty(slist)) {
        dtal_slist_pop(slist);
    }
error:
    return ERR;
}

int dtal_slist_destroy(SLinkedList *slist) {
    check(slist != NULL, "Invalid SLinkedList");
    dtal_slist_clear(*slist);
    free(*slist);
    *slist = NULL;
error:
    return ERR;
}

inline int dtal_slist_count(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    return slist->count;
error:
    return ERR;
}

inline inline void *dtal_slist_head(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    return slist->head != NULL ? (slist)->head->value : NULL;
error:
    return NULL;
}

inline void *dtal_slist_tail(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    return slist->tail != NULL ? (slist)->tail->value : NULL;
error:
    return NULL;
}

inline int dtal_slist_is_empty(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    return slist->count == 0;
error:
    return ERR;
}

int dtal_slist_push(SLinkedList slist, void *value) {
    check(slist != NULL, "Invalid SLinkedList");
    SLinkedListNode node = STRUCT_CALLOC(SLinkedListNode);
    check_mem(node);
    node->value = value;

    if (slist->head == NULL) {
        slist->head = node;
    } else {
        slist->tail->next = node;
    }

    slist->tail = node;
    slist->count++;
    return 0;
error:
    return ERR;
}

int dtal_slist_push_left(SLinkedList slist, void *value) {
    check(slist != NULL, "Invalid SLinkedList");
    SLinkedListNode node = STRUCT_CALLOC(SLinkedListNode);
    node->value = value;

    if (slist->tail == NULL) {
        slist->tail = node;
    } else {
        node->next = slist->head;
    }

    slist->head = node;
    slist->count++;
    return 0;
error:
    return ERR;
}

void *dtal_slist_remove(SLinkedList slist, SLinkedListNode node) {
    check(slist != NULL, "Invalid SLinkedList");
    check(node != NULL, "Invalid SLinkedListNode");
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
error:
    return NULL;
}

void *dtal_slist_pop(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    SLinkedListNode node = slist->tail;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
error:
    return NULL;
}

void *dtal_slist_pop_left(SLinkedList slist) {
    check(slist != NULL, "Invalid SLinkedList");
    SLinkedListNode node = slist->head;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
error:
    return NULL;
}
