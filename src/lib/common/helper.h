#ifndef dtal_helper_h
#define dtal_helper_h

/* Allocates a single object using malloc() */
#define MALLOC(type) MALLOC_ARRAY(1, type)

/* Allocates an array of objects using malloc() */
#define MALLOC_ARRAY(number, type) \
    ((type *)malloc((number) * sizeof(type)))

/* Allocates a single struct using calloc() */
#define STRUCT_CALLOC(type) CALLOC(struct type)

/* Allocates an array of objects using calloc() */
#define CALLOC(type) ARRAY_CALLOC(1, type)

/* Allocates an array of objects using calloc() */
#define ARRAY_CALLOC(number, type) \
    ((type *)calloc(number, sizeof(type)))

/* Reallocates an array of objects using realloc() */
#define REALLOC_ARRAY(pointer, number, type) \
    ((type *)realloc(pointer, (number) * sizeof(type)))

#endif
