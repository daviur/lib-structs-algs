#ifndef dtal_hashing_h
#define dtal_hashing_h

typedef struct key {
    void * value;
    int size;
} Key;

int dtal_division_hash(int range, Key key);

#endif

