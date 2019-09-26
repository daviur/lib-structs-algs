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

inline int is_full(List *list) {
    return list->count == list->size;
}

void extend_list(List *list) {
    list->array = realloc(list->array, 2*list->size*sizeof(void *));
    list->size *= 2;
}

void dtal_list_insert(List *list, int index, void *value) {
    if (is_full(list)) {
        extend_list(list);
    }

    for (int i = list->count; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = value;
    list->count++;
}

inline int is_quarter_full(List *list) {
    return list->count == list->size >> 2;
}

void shrink_list(List *list) {
    list->array = realloc(list->array, (list->size / 2)*sizeof(void *));
    list->size /= 2;
}

void *dtal_list_remove(List *list, int index) {
    if (is_quarter_full(list)) {
        shrink_list(list);
    }
    void *value = list->array[index];
    for (int i = index + 1; i < list->count; i++) {
        list->array[i - 1] = list->array[i];
    }
    list->count--;
    list->array[list->count] = NULL;
    return value;
}

inline void dtal_list_push(List *list, void *value) {
    dtal_list_insert(list, list->count, value);
}

inline void dtal_list_push_left(List *list, void *value) {
    dtal_list_insert(list, 0, value);
}

inline void *dtal_list_pop(List *list) {
    return dtal_list_remove(list, list->count-1);
}

inline void *dtal_list_pop_left(List *list) {
    return dtal_list_remove(list, 0);
}
