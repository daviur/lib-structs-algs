#include "dlist.h"

DLinkedList *dtal_dlist_create() {
    return calloc(1, sizeof(DLinkedList));
}

void dtal_dlist_destroy(DLinkedList *dlist) {
    LIST_FOREACH(dlist, head, next, node) {
        if (node->prev != NULL) {
            free(node->prev);
        }
    }

    free(dlist->tail);
    free(dlist);
}

void dtal_dlist_clear(DLinkedList *dlist) {
    LIST_FOREACH(dlist, head, next, node) {
        free(node->value);
    }
}

void dtal_dlist_clear_destroy(DLinkedList *dlist) {
    dtal_dlist_clear(dlist);
    dtal_dlist_destroy(dlist);
}

void dtal_dlist_push(DLinkedList *dlist, void *value) {
    DLinkedListNode *node = calloc(1, sizeof(DLinkedListNode));
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

void dtal_dlist_push_left(DLinkedList *dlist, void *value) {
    DLinkedListNode *node = calloc(1, sizeof(DLinkedListNode));
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

void *dtal_dlist_remove(DLinkedList *dlist, DLinkedListNode *node) {
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

void *dtal_dlist_pop(DLinkedList *dlist) {
    DLinkedListNode *node = dlist->tail;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
}

void *dtal_dlist_pop_left(DLinkedList *dlist) {
    DLinkedListNode *node = dlist->head;
    return node != NULL ? dtal_dlist_remove(dlist, node) : NULL;
}
