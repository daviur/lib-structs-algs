#include "list.h"

List *dtal_list_create(void) {
    return dtal_list_create_sized(16);
}

List *dtal_list_create_sized(int size) {
    List *list = calloc(1, sizeof(List));
    list->array = calloc(size, sizeof(void *));
    list->size = size;
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

void extend_list(List *list) {
    list->array = realloc(list->array, 2*list->size*sizeof(void *));
    list->size *= 2;
}

void dtal_list_push(List *list, void *value) {
    if (is_full(list)) {
        extend_list(list);
    }

    list->array[list->count] = value;
    list->count++;
}

void shrink_list(List *list) {
    list->array = realloc(list->array, (list->size / 2)*sizeof(void *));
    list->size /= 2;
}

void *dtal_list_pop(List *list) {
    if (is_quarter_full(list)) {
        shrink_list(list);
    }
    list->count--;
    void *value = list->array[list->count];
    list->array[list->count] = NULL;
    return value;
}
