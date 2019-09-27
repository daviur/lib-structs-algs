#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <slist.h>

SLinkedList slist;

static int setup(void **state) {
    slist = dtal_slist_create();
    return 0;
}

static int teardown(void **state) {
    dtal_slist_destroy(&slist);
    return 0;
}

static void test_slist_destroy(void **state) {
    assert_ptr_not_equal(NULL, slist);
    dtal_slist_destroy(&slist);
    assert_ptr_equal(NULL, slist);
}

static void test_slist_push_pop(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_slist_push(slist, value);
    assert_ptr_equal(value, dtal_slist_pop(slist));
    assert_ptr_equal(NULL, dtal_slist_head(slist));
    assert_ptr_equal(NULL, dtal_slist_tail(slist));
}

static void test_slist_push_left_pop_left(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_slist_push_left(slist, value);
    assert_ptr_equal(value, dtal_slist_pop_left(slist));
    assert_ptr_equal(NULL, dtal_slist_head(slist));
    assert_ptr_equal(NULL, dtal_slist_tail(slist));
}

static void test_slist_multiple_push_left_pop(void **state) {
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    dtal_slist_push_left(slist, value1);
    dtal_slist_push_left(slist, value2);
    dtal_slist_push_left(slist, value3);
    assert_ptr_equal(value1, dtal_slist_pop(slist));
    assert_ptr_equal(value2, dtal_slist_pop(slist));
    assert_ptr_equal(value3, dtal_slist_pop(slist));
}

static void test_slist_multiple_push_pop_left(void **state) {
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    dtal_slist_push(slist, value1);
    dtal_slist_push(slist, value2);
    dtal_slist_push(slist, value3);
    assert_ptr_equal(value1, dtal_slist_pop_left(slist));
    assert_ptr_equal(value2, dtal_slist_pop_left(slist));
    assert_ptr_equal(value3, dtal_slist_pop_left(slist));
}

static void test_slist_count(void **state) {
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    dtal_slist_push(slist, value1);
    dtal_slist_push(slist, value2);
    dtal_slist_push(slist, value3);
    assert_int_equal(3, dtal_slist_count(slist));
}

static void test_slist_head(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_slist_push_left(slist, value);
    assert_ptr_equal(value, dtal_slist_head(slist));
}

static void test_slist_tail(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_slist_push(slist, value);
    assert_ptr_equal(value, dtal_slist_tail(slist));
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_slist_push_pop, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_push_left_pop_left, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_multiple_push_left_pop, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_multiple_push_pop_left, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_count, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_head, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_tail, setup, teardown),
        cmocka_unit_test_setup_teardown(test_slist_destroy, setup, NULL),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

