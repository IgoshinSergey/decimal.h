#include "s21_decimal_test.h"

START_TEST(sub_0) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = DECIMAL_MAX;
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(0, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{1, 0, 0, (1 << 31)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = DECIMAL_MIN;
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{0, 0xffffffff, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(0xffffffff, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0xffffffff, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = DECIMAL_MIN;
  s21_decimal val2 = {{0, 0xffffffff, 0, (1 << 31)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(0xffffffff, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0xffffffff, res.bits[2]);
  unsigned bit_3 = (1 << 31);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{5, 0, 0, (1 << 16)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(0xfffffffe, res.bits[0]);
  ck_assert_int_eq(0xffffffff, res.bits[1]);
  ck_assert_int_eq(0xffffffff, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = DECIMAL_MAX;
  s21_decimal val2 = {{15, 0, 0, 1 << 16}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(0xfffffffe, res.bits[0]);
  ck_assert_int_eq(0xffffffff, res.bits[1]);
  ck_assert_int_eq(0xffffffff, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{1234, 0, 0, 2 << 16}};
  s21_decimal val2 = {{83540, 0, 0, 4 << 16}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(3986, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(3 << 16, res.bits[3]);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{1000, 0, 0, 2 << 16}};
  s21_decimal val2 = {{83500, 0, 0, 1 << 16}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(8340, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{10000, 0, 0, (2 << 16) | (1 << 31)}};
  s21_decimal val2 = {{580, 0, 0, (3 << 16) | (1 << 31)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(9942, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31 | 2 << 16);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{5500, 0, 0, (3 << 16) | (1 << 31)}};
  s21_decimal val2 = {{155, 0, 0, (1 << 16) | (1 << 31)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(10, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{15555, 0, 0, (4 << 16)}};
  s21_decimal val2 = {{4444500, 0, 0, (6 << 16) | (1 << 31)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(6, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  ck_assert_int_eq(0, res.bits[3]);
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{15666, 0, 0, (2 << 16) | (1 << 31)}};
  s21_decimal val2 = {{8433400, 0, 0, (4 << 16)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(1000, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{155, 0, 0, (29 << 16) | (1 << 31)}};
  s21_decimal val2 = {{200, 0, 0, (29 << 16)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
  ck_assert_int_eq(35, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
  unsigned bit_3 = (1 << 31 | 28 << 16);
  ck_assert_int_eq(bit_3, res.bits[3]);
}
END_TEST

Suite *suite_sub(void) {
  Suite *suite;
  TCase *tc;
  suite = suite_create("\033[30;43m S21_SUB \033[0m");
  tc = tcase_create("tcase_sub");

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);

  suite_add_tcase(suite, tc);
  return suite;
}