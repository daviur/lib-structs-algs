#include "slist.h"

SLinkedList *dtal_slist_create() {
    return calloc(1, sizeof(SLinkedList));
}

void dtal_slist_destroy(SLinkedList *slist) {
    SLinkedListNode *prev = NULL;
    LIST_FOREACH(slist, node) {
        if (prev != NULL) {
            free(prev);
        }
        prev = node;
    }

    free(slist->tail);
    free(slist);
}

void dtal_slist_clear(SLinkedList *slist) {
    LIST_FOREACH(slist, node) {
        free(node->value);
    }
}

void dtal_slist_clear_destroy(SLinkedList *slist) {
    dtal_slist_clear(slist);
    dtal_slist_destroy(slist);
}

void dtal_slist_push(SLinkedList *slist, void *value) {
    SLinkedListNode *node = calloc(1, sizeof(SLinkedListNode));
    node->value = value;

    if (slist->head == NULL) {
        slist->head = node;
    } else {
        slist->tail->next = node;
    }

   slist->tail = node;
    slist->count++;
}

void dtal_slist_push_left(SLinkedList *slist, void *value) {
    SLinkedListNode *node = calloc(1, sizeof(SLinkedListNode));
    node->value = value;

    if (slist->tail == NULL) {
        slist->tail = node;
    } else {
        node->next = slist->head;
    }

    slist->head = node;
    slist->count++;
}

void *dtal_slist_remove(SLinkedList *slist, SLinkedListNode *node) {
    SLinkedListNode *prev;
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

void *dtal_slist_pop(SLinkedList *slist) {
    SLinkedListNode *node = slist->tail;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
}

void *dtal_slist_pop_left(SLinkedList *slist) {
    SLinkedListNode *node = slist->head;
    return node != NULL ? dtal_slist_remove(slist, node) : NULL;
}
