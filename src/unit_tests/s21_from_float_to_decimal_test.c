#include "s21_decimal_test.h"

START_TEST(float_to_decimal_1) {
  float a = 123456789.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(123456800, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(0, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float a = 8e+29;
  int error = 1;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float a = 1e-29;
  int error = 1;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(s21_is_zero(dec), 1);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float a = 0.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(s21_is_zero(dec), 1);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float a = 1234.567890;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(3 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float a = 1.234567890;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(6 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float a = 0.1234567890;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(7 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float a = 0.00000000000001234567890;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(20 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_9) {
  float a = 0.0000000000000000000001234567890;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(28 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_10) {
  float a = 0.11;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(11, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(2 << 16, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_11) {
  float a = 1234567890.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(1234568000, dec.bits[0]);
  ck_assert_int_eq(0, dec.bits[1]);
  ck_assert_int_eq(0, dec.bits[2]);
  ck_assert_int_eq(0, dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_12) {
  float a = 12345678901234567890.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_big_decimal check_big = {0};
  check_big.bits[0] = 1234568;
  for (int i = 0; i < 13; i++) s21_mul_ten_big(&check_big);
  s21_decimal check = s21_big_decimal_to_decimal(check_big);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(check.bits[0], dec.bits[0]);
  ck_assert_int_eq(check.bits[1], dec.bits[1]);
  ck_assert_int_eq(check.bits[2], dec.bits[2]);
  ck_assert_int_eq(check.bits[3], dec.bits[3]);
}
END_TEST

START_TEST(float_to_decimal_13) {
  float a = 1234567890123456789012345678.0;
  int error = 0;
  int func_error = 0;
  s21_decimal dec = {0};
  func_error = s21_from_float_to_decimal(a, &dec);
  s21_big_decimal check_big = {0};
  check_big.bits[0] = 1234568;
  for (int i = 0; i < 21; i++) s21_mul_ten_big(&check_big);
  s21_decimal check = s21_big_decimal_to_decimal(check_big);
  ck_assert_int_eq(error, func_error);
  ck_assert_int_eq(check.bits[0], dec.bits[0]);
  ck_assert_int_eq(check.bits[1], dec.bits[1]);
  ck_assert_int_eq(check.bits[2], dec.bits[2]);
  ck_assert_int_eq(check.bits[3], dec.bits[3]);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s = suite_create("\033[30;43m S21_FROM_FLOAT_TO_DECIMAL \033[0m");
  TCase *tc = tcase_create("tcase_from_float_to_decimal");

  tcase_add_test(tc, float_to_decimal_1);
  tcase_add_test(tc, float_to_decimal_2);
  tcase_add_test(tc, float_to_decimal_3);
  tcase_add_test(tc, float_to_decimal_4);
  tcase_add_test(tc, float_to_decimal_5);
  tcase_add_test(tc, float_to_decimal_6);
  tcase_add_test(tc, float_to_decimal_7);
  tcase_add_test(tc, float_to_decimal_8);
  tcase_add_test(tc, float_to_decimal_9);
  tcase_add_test(tc, float_to_decimal_10);
  tcase_add_test(tc, float_to_decimal_11);
  tcase_add_test(tc, float_to_decimal_12);
  tcase_add_test(tc, float_to_decimal_13);

  suite_add_tcase(s, tc);
  return s;
}