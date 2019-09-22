#include "list.h"

List *dtal_list_create() {
    List *list = calloc(1, sizeof(List));
    list->array = calloc(8, sizeof(void *));
    list->size = 8;
    return list;
}

void dtal_list_destroy(List *list) {
    free(list->array);
    free(list);
}

void dtal_list_clear(List *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->array[i]);
        list->array[i] = NULL;
    }
    list->count = 0;
}

void dtal_list_clear_destroy(List *list) {
    dtal_list_clear(list);
    dtal_list_destroy(list);
}

int is_full(List *list) {
    return list->count == list->size;
}

int is_quarter_full(List *list) {
    return list->count == list->size >> 2;
 }

void dtal_list_push(List *list, void *value) {
    list->array[list->count] = value;
    list->count++;

    /* if (is_full(list)) { */

    /* } */
}

void *dtal_list_pop(List *list) {
    list->count--;

    /* if (is_quarter_full(list)) { */

    /* } */

    void *value = list->array[list->count];
    list->array[list->count] = 0;
    return value;
}
