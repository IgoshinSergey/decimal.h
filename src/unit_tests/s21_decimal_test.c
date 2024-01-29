#include "s21_decimal_test.h"

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void run_testcase(Suite *testcase) {
  printf("\n");
  SRunner *suite_runner = srunner_create(testcase);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
}

void run_tests(void) {
  printf("\n\033[30;43m -=S21_DECIMAL_TESTS=- \033[0m\n");
  Suite *case_list[] = {suite_sub(),
                        suite_div(),
                        suite_is_greater_or_equal(),
                        suite_is_less_or_equal(),
                        suite_is_not_equal(),
                        suite_negate(),
                        suite_round(),
                        suite_from_decimal_to_float(),
                        suite_from_float_to_decimal(),
                        suite_add(),
                        suite_mul(),
                        suite_is_less(),
                        suite_is_greater(),
                        suite_is_equal(),
                        suite_from_int_to_decimal(),
                        suite_from_decimal_to_int(),
                        suite_floor(),
                        suite_truncate(),
                        NULL};
  for (Suite **cur_test_case = case_list; *cur_test_case != NULL;
       cur_test_case++) {
    run_testcase(*cur_test_case);
  }
}

int main() {
  run_tests();
  return 0;
}