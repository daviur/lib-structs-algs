#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <dlist.h>

DLinkedList *dlist;

static int setup(void **state) {
    dlist = dtal_dlist_create();
    return 0;
}

static int teardown(void **state) {
    dtal_dlist_clear_destroy(dlist);
    return 0;
}

static void test_dlist_push_pop(void **state) {
    int *value = malloc(sizeof(int));
    dtal_dlist_push(dlist, value);
    assert_ptr_equal(value, dtal_dlist_pop(dlist));
    assert_ptr_equal(NULL, dlist->head);
    assert_ptr_equal(NULL, dlist->tail);
}

static void test_dlist_push_left_pop_left(void **state) {
    int *value = malloc(sizeof(int));
    dtal_dlist_push_left(dlist, value);
    assert_ptr_equal(value, dtal_dlist_pop_left(dlist));
    assert_ptr_equal(NULL, dlist->head);
    assert_ptr_equal(NULL, dlist->tail);
}

static void test_dlist_multiple_push_left_pop(void **state) {
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    dtal_dlist_push_left(dlist, value1);
    dtal_dlist_push_left(dlist, value2);
    dtal_dlist_push_left(dlist, value3);
    assert_ptr_equal(value1, dtal_dlist_pop(dlist));
    assert_ptr_equal(value2, dtal_dlist_pop(dlist));
    assert_ptr_equal(value3, dtal_dlist_pop(dlist));
}

static void test_dlist_multiple_push_pop_left(void **state) {
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    dtal_dlist_push(dlist, value1);
    dtal_dlist_push(dlist, value2);
    dtal_dlist_push(dlist, value3);
    assert_ptr_equal(value1, dtal_dlist_pop_left(dlist));
    assert_ptr_equal(value2, dtal_dlist_pop_left(dlist));
    assert_ptr_equal(value3, dtal_dlist_pop_left(dlist));
}

static void test_dlist_count(void **state) {
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    dtal_dlist_push(dlist, value1);
    dtal_dlist_push(dlist, value2);
    dtal_dlist_push(dlist, value3);
    assert_int_equal(3, dtal_dlist_count(dlist));
}

static void test_dlist_head(void **state) {
    int *value = malloc(sizeof(int));
    dtal_dlist_push_left(dlist, value);
    assert_ptr_equal(value, dtal_dlist_head(dlist));
}

static void test_dlist_tail(void **state) {
    int *value = malloc(sizeof(int));
    dtal_dlist_push(dlist, value);
    assert_ptr_equal(value, dtal_dlist_tail(dlist));
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_dlist_push_pop),
        cmocka_unit_test(test_dlist_push_left_pop_left),
        cmocka_unit_test(test_dlist_multiple_push_left_pop),
        cmocka_unit_test(test_dlist_multiple_push_pop_left),
        cmocka_unit_test(test_dlist_count),
        cmocka_unit_test(test_dlist_head),
        cmocka_unit_test(test_dlist_tail),
    };
    return cmocka_run_group_tests(tests, setup, teardown);
}
