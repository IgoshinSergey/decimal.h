#include "s21_decimal_test.h"

START_TEST(test_negate_1) {
  s21_decimal x = DECIMAL_MAX;
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_2) {
  s21_decimal x = DECIMAL_MIN;
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_3) {
  s21_decimal x = {{0, 10, 2, (10 << 16) | (1 < 31)}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_4) {
  s21_decimal x = {{234567, 2456, 7654, (21 << 16)}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_5) {
  s21_decimal x = {{14, 0, 0, (1 << 16)}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_6) {
  s21_decimal x = {{0, 0, 0, (1 << 16)}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_7) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_8) {
  s21_decimal x = {{0xffffffff, 0, 0, 0}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_9) {
  s21_decimal x = {{0xffffffff, 0xffffffff, 0, 5 << 16}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_10) {
  s21_decimal x = {{0xffffffff, 0xffffffff, 0xffffffff, (5 << 16) | (1 << 31)}};
  s21_decimal res = {{0}};
  int result = s21_negate(x, &res);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(res.bits[0], x.bits[0]);
  ck_assert_int_eq(res.bits[1], x.bits[1]);
  ck_assert_int_eq(res.bits[2], x.bits[2]);
  bool sign1 = s21_get_sign(x);
  bool sign2 = s21_get_sign(res);
  int scale1 = s21_get_scale(x);
  int scale2 = s21_get_scale(res);
  ck_assert_int_eq(scale1, scale2);
  ck_assert_int_ne(sign1, sign2);
}
END_TEST

START_TEST(test_negate_11) {
  s21_decimal x = {{0, 0, 0, 0}};
  s21_decimal *res = NULL;
  int result = s21_negate(x, res);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_negate(void) {
  Suite *suite;
  TCase *tc;
  suite = suite_create("\033[30;43m S21_NEGATE \033[0m");
  tc = tcase_create("tcase_negate");

  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);
  tcase_add_test(tc, test_negate_3);
  tcase_add_test(tc, test_negate_4);
  tcase_add_test(tc, test_negate_5);
  tcase_add_test(tc, test_negate_6);
  tcase_add_test(tc, test_negate_7);
  tcase_add_test(tc, test_negate_8);
  tcase_add_test(tc, test_negate_9);
  tcase_add_test(tc, test_negate_10);
  tcase_add_test(tc, test_negate_11);

  suite_add_tcase(suite, tc);
  return suite;
}