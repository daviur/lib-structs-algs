#include <stdlib.h>

#include "helper.h"
#include "dbg.h"
#include "list.h"

#define SIZE 16

struct List {
    int count;
    int size;
    void **array;
};

List dtal_list_create(void) {
    return dtal_list_create_sized(SIZE);
}

List dtal_list_create_sized(int size) {
    List list = STRUCT_CALLOC(List);
    check_mem(list);
    list->array = calloc(size, sizeof(void *));
    list->size = size;
    return list;
error:
    return NULL;
}

int dtal_list_clear(List list) {
    check(list != NULL, "Invalid List");
    for (int i = 0; i < list->count; i++) {
        list->array[i] = NULL;
    }
    list->array = realloc(list->array, SIZE*sizeof(void *));
    list->size = SIZE;
    list->count = 0;
error:
    return ERR;
}

int dtal_list_destroy(List *list) {
    check(list != NULL, "Invalid List");
    free((*list)->array);
    free(*list);
    *list = NULL;
error:
    return ERR;
}

inline int dtal_list_count(List list) {
    check(list != NULL, "Invalid List");
    return list->count;
error:
    return ERR;
}

inline int dtal_list_size(List list) {
    check(list != NULL, "Invalid List");
    return list->size;
error:
    return ERR;
}

inline void *dtal_list_head(List list) {
    check(list != NULL, "Invalid List");
    return list->count > 0 ? list->array[0] : NULL;
error:
    return NULL;
}

inline void *dtal_list_tail(List list) {
    check(list != NULL, "Invalid List");
    return list->count > 0 ? list->array[list->count - 1] : NULL;
error:
    return NULL;
}

inline int dtal_list_is_empty(List list) {
    check(list != NULL, "Invalid List");
    return list->count == 0;
error:
    return ERR;
}

void *dtal_list_get(List list, int index) {
    check(list != NULL, "Invalid List");
    return list->array[index];
error:
    return NULL;
}

inline int is_full(List list) {
    return list->count == list->size;
}

int extend_list(List list) {
    list->array = realloc(list->array, 2*list->size*sizeof(void *));
    list->size *= 2;
}

int dtal_list_insert(List list, int index, void *value) {
    check(list != NULL, "Invalid List");
    check(0 <= index && index <= list->count, "Index must be 0 <= index <= count");
    if (is_full(list)) {
        extend_list(list);
    }

    for (int i = list->count; i > index; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index] = value;
    list->count++;
error:
    return ERR;
}

inline int is_quarter_full(List list) {
    return list->count == list->size >> 2;
}

int shrink_list(List list) {
    check(list != NULL, "Invalid List");
    list->array = realloc(list->array, (list->size / 2)*sizeof(void *));
    list->size /= 2;
error:
    return ERR;
}

void *dtal_list_remove(List list, int index) {
    check(list != NULL, "Invalid List");
    check(0 <= index && index <= list->count, "Index must be 0 <= index <= count");
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
error:
    return NULL;
}

inline int dtal_list_push(List list, void *value) {
    check(list != NULL, "Invalid List");
    dtal_list_insert(list, list->count, value);
error:
    return ERR;
}

inline int dtal_list_push_left(List list, void *value) {
    check(list != NULL, "Invalid List");
    dtal_list_insert(list, 0, value);
error:
    return ERR;
}

inline void *dtal_list_pop(List list) {
    check(list != NULL, "Invalid List");
    return dtal_list_remove(list, list->count-1);
error:
    return NULL;
}

inline void *dtal_list_pop_left(List list) {
    check(list != NULL, "Invalid List");
    return dtal_list_remove(list, 0);
error:
    return NULL;
}
