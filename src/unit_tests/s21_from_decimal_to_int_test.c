#include "s21_decimal_test.h"

START_TEST(s21_from_decimal_to_int_test_1) {
  s21_decimal src = {0};
  int org_res = 0, s21_res = 0;
  int return_s21 = s21_from_decimal_to_int(src, &s21_res);
  ck_assert_int_eq(0, org_res);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_2) {
  s21_decimal src = {{0x1, 0x0, 0x0, 0x0}};
  int org_res = 1, s21_res = 0;
  int return_s21 = s21_from_decimal_to_int(src, &s21_res);
  ck_assert_int_eq(s21_res, org_res);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_3) {
  s21_decimal src = {{INT_MAX, 0x0, 0x0, 0x0}};
  int org_res = INT_MAX, s21_res = 0;
  int return_s21 = s21_from_decimal_to_int(src, &s21_res);
  ck_assert_int_eq(s21_res, org_res);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_4) {
  s21_decimal src = {{INT_MIN, 0x0, 0x0, 0x0}};
  int org_res = INT_MIN, s21_res = 0;
  int return_s21 = s21_from_decimal_to_int(src, &s21_res);
  ck_assert_int_eq(s21_res, org_res);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_5) {
  s21_decimal src = DECIMAL_MAX;
  int org_res = 0, s21_res = 0;
  int return_s21 = s21_from_decimal_to_int(src, &s21_res);
  ck_assert_int_eq(s21_res, org_res);
  ck_assert_int_eq(1, return_s21);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *suite;
  TCase *tcase;
  suite = suite_create("\033[30;43m S21_FROM_DECIMAL_TO_INT \033[0m");
  tcase = tcase_create("tcase_from_decimal_to_int");

  tcase_add_test(tcase, s21_from_decimal_to_int_test_1);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_2);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_3);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_4);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_5);

  suite_add_tcase(suite, tcase);
  return suite;
}