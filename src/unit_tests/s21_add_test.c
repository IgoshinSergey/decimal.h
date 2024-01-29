#include "s21_decimal_test.h"

START_TEST(s21_add_test_1) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int return_s21 = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
  ck_assert_int_eq(return_s21, 0);
}
END_TEST

START_TEST(s21_add_test_2) {
  s21_decimal value_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal org_res = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_3) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};

  s21_decimal org_res = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_4) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal org_res = DECIMAL_MAX;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_5) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = DECIMAL_MAX;

  s21_decimal org_res = DECIMAL_MAX;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_6) {
  s21_decimal value_1 = DECIMAL_MIN;
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x0}};

  s21_decimal org_res = DECIMAL_MIN;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_8) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = DECIMAL_MIN;

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_9) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31}};

  s21_decimal org_res = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_10) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  s21_decimal org_res = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_11) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};

  s21_decimal org_res = {{0x0, 0x0, 0x1, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_12) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal value_2 = {{0x5, 0x0, 0x0, 0x80010000}};

  s21_decimal org_res = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_14) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.4999999999999999999999999999
  s21_decimal value_2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  s21_decimal org_res = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_16) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.9999999999999999999999999000
  s21_decimal value_2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  s21_decimal org_res = {{0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_17) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0000000000000000000000000001
  s21_decimal value_2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  s21_decimal org_res = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_18) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal value_2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  s21_decimal org_res = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_19) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal value_2 = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  s21_decimal org_res = {{0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_20) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x80000000}};

  s21_decimal org_res = DECIMAL_MAX;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_22) {
  s21_decimal value_1 = DECIMAL_MIN;
  s21_decimal value_2 = {{0x0, 0x0, 0x0, 0x80000000}};

  s21_decimal org_res = DECIMAL_MIN;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_23) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = DECIMAL_MIN;

  s21_decimal org_res = DECIMAL_MIN;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_24) {
  s21_decimal value_1 = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal value_2 = DECIMAL_MIN;

  s21_decimal org_res = DECIMAL_MIN;
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(SUCCESS, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

/* ========== 1 TESTS ========== */

START_TEST(s21_add_test_25) {
  s21_decimal value_1 = DECIMAL_MAX;
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 0x0}};

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(1, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_26) {
  s21_decimal value_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal value_2 = DECIMAL_MAX;

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(1, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_add_test_27) {
  s21_decimal value_1 = DECIMAL_MIN;
  s21_decimal value_2 = {{0x1, 0x0, 0x0, 1 << 31}};

  s21_decimal org_res = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal s21_res = {{0x0, 0x0, 0x0, 0x0}};

  int s21_out = s21_add(value_1, value_2, &s21_res);

  ck_assert_int_eq(2, s21_out);
  ck_assert_int_eq(org_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(org_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(org_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(org_res.bits[3], s21_res.bits[3]);
}
END_TEST

Suite *suite_add(void) {
  Suite *suite = suite_create("\033[30;43m S21_ADD \033[0m");
  ;
  TCase *tcase = tcase_create("tcase_add");

  tcase_add_test(tcase, s21_add_test_1);
  tcase_add_test(tcase, s21_add_test_2);
  tcase_add_test(tcase, s21_add_test_3);
  tcase_add_test(tcase, s21_add_test_4);
  tcase_add_test(tcase, s21_add_test_5);
  tcase_add_test(tcase, s21_add_test_6);
  tcase_add_test(tcase, s21_add_test_8);
  tcase_add_test(tcase, s21_add_test_9);
  tcase_add_test(tcase, s21_add_test_10);
  tcase_add_test(tcase, s21_add_test_11);
  tcase_add_test(tcase, s21_add_test_12);
  tcase_add_test(tcase, s21_add_test_14);
  tcase_add_test(tcase, s21_add_test_16);
  tcase_add_test(tcase, s21_add_test_17);
  tcase_add_test(tcase, s21_add_test_18);
  tcase_add_test(tcase, s21_add_test_19);
  tcase_add_test(tcase, s21_add_test_20);
  tcase_add_test(tcase, s21_add_test_20);
  tcase_add_test(tcase, s21_add_test_22);
  tcase_add_test(tcase, s21_add_test_23);
  tcase_add_test(tcase, s21_add_test_24);

  tcase_add_test(tcase, s21_add_test_25);
  tcase_add_test(tcase, s21_add_test_26);
  tcase_add_test(tcase, s21_add_test_27);

  suite_add_tcase(suite, tcase);
  return suite;
}