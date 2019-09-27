#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <list.h>

List list;

static int setup(void **state) {
    list = dtal_list_create_sized(2);
    return 0;
}

static int teardown(void **state) {
    dtal_list_destroy(&list);
    return 0;
}

static void test_list_destroy(void **state) {
    assert_ptr_not_equal(NULL, list);
    dtal_list_destroy(&list);
    assert_ptr_equal(NULL, list);
}

static void test_list_push_pop(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_list_push(list, value);
    assert_int_equal(1, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
    assert_ptr_equal(value, dtal_list_pop(list));
    assert_int_equal(0, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
}

static void test_list_count_size(void **state) {
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    int *value4 = malloc(sizeof(int));
    *value1 = 4;
    int *value5 = malloc(sizeof(int));
    *value2 = 5;
    int *value6 = malloc(sizeof(int));
    *value3 = 6;
    assert_int_equal(0, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
    dtal_list_push(list, value1);
    assert_int_equal(1, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
    dtal_list_push(list, value2);
    assert_int_equal(2, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
    dtal_list_push(list, value3);
    assert_int_equal(3, dtal_list_count(list));
    assert_int_equal(2*2, dtal_list_size(list));
    dtal_list_push(list, value4);
    assert_int_equal(4, dtal_list_count(list));
    assert_int_equal(2*2, dtal_list_size(list));
    dtal_list_push(list, value5);
    assert_int_equal(5, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_push(list, value6);
    assert_int_equal(6, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(5, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(4, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(3, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(2, dtal_list_count(list));
    assert_int_equal(2*2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(1, dtal_list_count(list));
    assert_int_equal(2*2, dtal_list_size(list));
    dtal_list_pop(list);
    assert_int_equal(0, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
}

static void test_list_head(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_list_push(list, value);
    assert_ptr_equal(value, dtal_list_head(list));
}

static void test_list_tail(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_list_push(list, value);
    assert_ptr_equal(value, dtal_list_tail(list));
}

static void test_list_push_left_pop_left(void **state) {
    int *value = malloc(sizeof(int));
    *value = 9999;
    dtal_list_push_left(list, value);
    assert_int_equal(1, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
    assert_ptr_equal(value, dtal_list_pop_left(list));
    assert_int_equal(0, dtal_list_count(list));
    assert_int_equal(2, dtal_list_size(list));
}

static void test_list_get(void **state) {
    int *value1 = malloc(sizeof(int));
    *value1 = 1;
    int *value2 = malloc(sizeof(int));
    *value2 = 2;
    int *value3 = malloc(sizeof(int));
    *value3 = 3;
    dtal_list_push(list, value1);
    dtal_list_push(list, value2);
    dtal_list_push(list, value3);
    assert_ptr_equal(value1, dtal_list_get(list, 0));
    assert_ptr_equal(value2, dtal_list_get(list, 1));
    assert_ptr_equal(value3, dtal_list_get(list, 2));
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_list_get, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_push_pop, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_push_left_pop_left, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_count_size, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_head, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_tail, setup, teardown),
        cmocka_unit_test_setup_teardown(test_list_destroy, setup, NULL),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
