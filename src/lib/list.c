#include "list.h"

List *dtal_list_create() {
    return calloc(1, sizeof(List));
}

void dtal_list_destroy(List *list) {
    LIST_FOREACH(list, first, next, node) {
        if (node->prev) {
            free(node->prev);
        }
    }

    free(list->last);
    free(list);
}

void dtal_list_clear(List *list) {
    LIST_FOREACH(list, first, next, node) {
        if (node->prev) {
            free(node->value);
        }
    }
}

void dtal_list_clear_destroy(List *list) {
    dtal_list_clear(list);
    dtal_list_destroy(list);
}

void dtal_list_push(List *list, void *value) {
    ListNode *node = calloc(1, sizeof(ListNode));

    node->value = value;

    if (list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;
}

void dtal_list_push_left(List *list, void *value) {
    ListNode *node = calloc(1, sizeof(ListNode));

    node->value = value;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->first->prev = node;
        node->next = list->first;
        list->first = node;
    }

    list->count++;
}

void *dtal_list_remove(List *list, ListNode *node) {
    void *value = NULL;

    if (node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if (node == list->first) {
        list->first = node->next;
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    list->count--;
    value = node->value;
    free(node);

    return value;
}

void *dtal_list_pop(List *list) {
    ListNode *node = list->last;
    return node != NULL ? dtal_list_remove(list, node) : NULL;
}

void *dtal_list_pop_left(List *list) {
    ListNode *node = list->first;
    return node != NULL ? dtal_list_remove(list, node) : NULL;
}
