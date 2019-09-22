#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <list.h>

List *list;

static int setup(void **state) {
    list = dtal_list_create();
    return 0;
}

static int teardown(void **state) {
    dtal_list_clear_destroy(list);
    return 0;
}

static void test_list_push_pop(void **state) {
    int *value = malloc(sizeof(int));
    dtal_list_push(list, value);
    assert_ptr_equal(value, dtal_list_pop(list));
}

/* static void test_list_push_left_pop_left(void **state) { */
/*     int *value = malloc(sizeof(int)); */
/*     dtal_list_push_left(list, value); */
/*     assert_ptr_equal(value, dtal_list_pop_left(list)); */
/* } */

/* static void test_list_multiple_push_left_pop(void **state) { */
/*     int *value1 = malloc(sizeof(int)); */
/*     int *value2 = malloc(sizeof(int)); */
/*     int *value3 = malloc(sizeof(int)); */
/*     dtal_list_push_left(list, value1); */
/*     dtal_list_push_left(list, value2); */
/*     dtal_list_push_left(list, value3); */
/*     assert_ptr_equal(value1, dtal_list_pop(list)); */
/*     assert_ptr_equal(value2, dtal_list_pop(list)); */
/*     assert_ptr_equal(value3, dtal_list_pop(list)); */
/* } */

/* static void test_list_multiple_push_pop_left(void **state) { */
/*     int *value1 = malloc(sizeof(int)); */
/*     int *value2 = malloc(sizeof(int)); */
/*     int *value3 = malloc(sizeof(int)); */
/*     dtal_list_push(list, value1); */
/*     dtal_list_push(list, value2); */
/*     dtal_list_push(list, value3); */
/*     assert_ptr_equal(value1, dtal_list_pop_left(list)); */
/*     assert_ptr_equal(value2, dtal_list_pop_left(list)); */
/*     assert_ptr_equal(value3, dtal_list_pop_left(list)); */
/* } */

static void test_list_count(void **state) {
    int *value1 = malloc(sizeof(int));
    int *value2 = malloc(sizeof(int));
    int *value3 = malloc(sizeof(int));
    dtal_list_push(list, value1);
    dtal_list_push(list, value2);
    dtal_list_push(list, value3);
    assert_int_equal(3, dtal_list_count(list));
}

/* static void test_list_head(void **state) { */
/*     int *value = malloc(sizeof(int)); */
/*     dtal_list_push_left(list, value); */
/*     assert_ptr_equal(value, dtal_list_head(list)); */
/* } */

/* static void test_list_tail(void **state) { */
/*     int *value = malloc(sizeof(int)); */
/*     dtal_list_push(list, value); */
/*     assert_ptr_equal(value, dtal_list_tail(list)); */
/* } */

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_list_push_pop),
        /* cmocka_unit_test(test_list_push_left_pop_left), */
        /* cmocka_unit_test(test_list_multiple_push_left_pop), */
        /* cmocka_unit_test(test_list_multiple_push_pop_left), */
        cmocka_unit_test(test_list_count),
        /* cmocka_unit_test(test_list_head), */
        /* cmocka_unit_test(test_list_tail), */
    };
    return cmocka_run_group_tests(tests, setup, teardown);
}


