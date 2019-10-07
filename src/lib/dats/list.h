#ifndef dtal_list_h
#define dtal_list_h

typedef struct List * List;

List dtal_list_create(void);
List dtal_list_create_sized(int size);
int dtal_list_destroy(List *list);
int dtal_list_clear(List list);

int dtal_list_count(List list);
int dtal_list_size(List list);
void *dtal_list_head(List list);
void *dtal_list_tail(List list);
int dtal_list_is_empty(List list);

void *dtal_list_get(List list, int index);

int dtal_list_push(List list, void *value);
int dtal_list_push_left(List list, void *value);
void *dtal_list_pop(List list);
void *dtal_list_pop_left(List list);
int dtal_list_insert(List list, int index, void *value);
void *dtal_list_remove(List list, int index);

#define LIST_FOREACH(L, C) \
    void *C = NULL; \
    for (int i = 0; i < dtal_list_count(L); i++) { \
        C = dtal_list_get(L, i);

#endif

