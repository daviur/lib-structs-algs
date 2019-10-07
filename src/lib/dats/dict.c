#include <stdlib.h>

#include "helper.h"
#include "dict.h"
#include "dlist.h"

#define SIZE 16

struct Dict {
    int count;
    int size;
    DLinkedList* array;
};

Dict dtal_dict_create() {
    return dtal_dict_create_sized(SIZE);
}

Dict dtal_dict_create_sized(int size) {
    Dict dict = STRUCT_CALLOC(Dict);
    dict->array = ARRAY_CALLOC(size, DLinkedList);
    dict->size = size;

    for (int i = 0; i < size; i++) {
        dict->array[i] = dtal_dlist_create();
    }
    return dict;
}

void dtal_dict_clear(Dict dict) {
    for (int i = 0; i < dict->size; i++) {
        dtal_dlist_clear(dict->array[i]);
    }
    dict->count = dict->size = 0;
}

void dtal_dict_destroy(Dict* dict) {
    for (int i = 0; i < (*dict)->size; i++) {
        dtal_dlist_destroy((*dict)->array + i);
    }
    free(*dict);
    *dict = NULL;
}

void dtal_dict_insert(Dict dict, void *key, void *value) {

}
