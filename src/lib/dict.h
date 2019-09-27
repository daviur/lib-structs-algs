#ifndef dtal_dict_h
#define dtal_dict_h

typedef struct Dict * Dict;

Dict dtal_dict_create();
Dict dtal_dict_create_sized(int size);
void dtal_dict_clear(Dict dict);
void dtal_dict_destroy(Dict* dict);

void dtal_dict_insert(Dict dict, void *key, void *value);

#endif
