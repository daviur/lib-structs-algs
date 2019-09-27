#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <dict.h>

Dict dict;

static int setup(void **state) {
    dict = dtal_dict_create();
    return 0;
}

static int teardown(void **state) {
    dtal_dict_destroy(&dict);
    return 0;
}

static void test_dict_destroy(void **state) {
    assert_ptr_not_equal(NULL, dict);
    dtal_dict_destroy(&dict);
    assert_ptr_equal(NULL, dict);
}

static void test_dict_insert(void **state) {

}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_dict_insert, setup, teardown),
        cmocka_unit_test_setup_teardown(test_dict_destroy, setup, NULL),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
