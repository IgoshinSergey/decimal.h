#include "s21_decimal_test.h"

START_TEST(div_0) {
  s21_decimal val1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal val2 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{1, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  // 1 / 0
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{15000, 0, 0, (3 << 16)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  // 15 / 8 = 1.875
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(1875, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(3 << 16, res.bits[3]);
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{15000, 0, 0, (1 << 31) | (3 << 16)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  // -15 / 8 = -1.875
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(1875, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31 | 3 << 16);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{15000, 0, 0, (3 << 16)}};
  s21_decimal val2 = {{8, 0, 0, (1 << 31)}};
  s21_decimal res = {{0}};
  // 15 / -8 = -1.875
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(1875, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31 | 3 << 16);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(div_5) {
  s21_decimal val1 = {{15000, 0, 0, (1 << 31) | (3 << 16)}};
  s21_decimal val2 = {{8, 0, 0, (1 << 31)}};
  s21_decimal res = {{0}};
  // -15 / -8 = 1.875
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(1875, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq((3 << 16), res.bits[3]);
}
END_TEST

START_TEST(div_6) {
  s21_decimal val1 = {{5, 0, 0, 0}};
  s21_decimal val2 = {{11, 0, 0, 0}};
  s21_decimal res = {{0}};
  // 5 / 11 = 0,(45)
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
// END_TEST

START_TEST(div_7) {
  s21_decimal val1 = {{6, 0, 0, 0}};
  s21_decimal val2 = {{11, 0, 0, 0}};
  s21_decimal res = {{0}};
  // 6 / 11 = 0,(54)
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_8) {
  s21_decimal val1 = {{5, 0, 0, 0}};
  s21_decimal val2 = {{9, 0, 0, 0}};
  s21_decimal res = {{0}};
  // 5 / 9 = 0,(5)
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_9) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{1, 0, 0, (1 << 16)}};
  s21_decimal res = {{0}};
  // +INF
  ck_assert_int_eq(1, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_10) {
  s21_decimal val1 = DECIMAL_MIN;
  s21_decimal val2 = {{1, 0, 0, (1 << 16)}};
  s21_decimal res = {{0}};
  // -INF
  ck_assert_int_eq(2, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_11) {
  s21_decimal val1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  s21_decimal val2 = {{2, 0, 0, 1 << 31}};
  s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 1 << 31}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(check.bits[0], res.bits[0]);
  ck_assert_int_eq(check.bits[1], res.bits[1]);
  ck_assert_int_eq(check.bits[2], res.bits[2]);
  ck_assert_int_eq(check.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_12) {
  s21_decimal val1 = {{35, 0, 0, (1 << 16)}};
  s21_decimal val2 = {{5, 0, 0, (2 << 16)}};
  s21_decimal check = {{70, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(check.bits[0], res.bits[0]);
  ck_assert_int_eq(check.bits[1], res.bits[1]);
  ck_assert_int_eq(check.bits[2], res.bits[2]);
  ck_assert_int_eq(check.bits[3], res.bits[3]);
}
END_TEST

START_TEST(div_13) {
  s21_decimal val1 = {{754, 0, 0, (30 << 16)}};
  s21_decimal val2 = {{2, 0, 0, (1 << 16)}};
  s21_decimal check = {{38, 0, 0, (28 << 16)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
  ck_assert_int_eq(check.bits[0], res.bits[0]);
  ck_assert_int_eq(check.bits[1], res.bits[1]);
  ck_assert_int_eq(check.bits[2], res.bits[2]);
  ck_assert_int_eq(check.bits[3], res.bits[3]);
}
END_TEST

Suite *suite_div(void) {
  Suite *suite = suite_create("\033[30;43m S21_DIV \033[0m");
  TCase *tc = tcase_create("tcase_div");

  tcase_add_test(tc, div_0);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);

  suite_add_tcase(suite, tc);
  return suite;
}