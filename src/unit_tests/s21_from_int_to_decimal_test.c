#include "s21_decimal_test.h"

START_TEST(s21_from_int_to_decimal_test_1) {
  int src = 0;

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_2) {
  int src = -0;

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_3) {
  int src = 1;

  s21_decimal org_res = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_4) {
  int src = -1;

  s21_decimal org_res = {{0x1, 0x0, 0x0, 1 << 31}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_5) {
  int src = INT_MAX;

  s21_decimal org_res = {{INT_MAX, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_6) {
  int src = INT_MIN;

  s21_decimal org_res = {{INT_MIN, 0x0, 0x0, 1 << 31}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_7) {
  int src = 1234567890;

  s21_decimal org_res = {{0x499602D2, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_from_int_to_decimal(src, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *suite;
  TCase *tcase;
  suite = suite_create("\033[30;43m S21_FROM_INT_TO_DECIMAL \033[0m");
  tcase = tcase_create("tcase_from_int_to_decimal");

  tcase_add_test(tcase, s21_from_int_to_decimal_test_1);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_2);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_3);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_4);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_5);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_6);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}