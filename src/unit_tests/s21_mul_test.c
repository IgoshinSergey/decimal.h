#include "s21_decimal_test.h"

START_TEST(mul_0) {
  s21_decimal val1 = {{12345, 0, 0, 0}};
  s21_decimal val2 = {{100, 0, 0, 0}};
  s21_decimal res = {0};

  int ret = s21_mul(val1, val2, &res);
  ck_assert_int_eq(ret, 0);
  ck_assert_int_eq(1234500, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{11, 0, 0, 1 << 16}};
  s21_decimal res = {0};

  int ret = s21_mul(val1, val2, &res);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{11, 0, 0, (1 << 16) | (1 << 31)}};
  s21_decimal res = {0};

  int ret = s21_mul(val1, val2, &res);
  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {0};
  s21_decimal res = {0};

  int ret = s21_mul(val1, val2, &res);
  ck_assert_int_eq(ret, 0);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(0, res.bits[i]);
  }
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("\033[30;43m S21_MUL \033[0m");
  TCase *tc = tcase_create("tcase_mul");

  tcase_add_test(tc, mul_0);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);

  suite_add_tcase(s, tc);
  return s;
}