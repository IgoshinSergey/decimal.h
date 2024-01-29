#include "s21_decimal_test.h"

START_TEST(test_is_not_equal_1) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 0;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_2) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 16}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_3) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_4) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_5) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_6) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_7) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_8) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_9) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_10) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_11) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_12) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_13) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_14) {
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_15) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_16) {
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_17) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_18) {
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_19) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_20) {
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_21) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_22) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_23) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_24) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_25) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_26) {
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_27) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_28) {
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_29) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_30) {
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_31) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_32) {
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_33) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_34) {
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_35) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_36) {
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_37) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_38) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_39) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_40) {
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_41) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_42) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_43) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_44) {
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_45) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_46) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_47) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_48) {
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_49) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_50) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_51) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_52) {
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_53) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_54) {
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_55) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_56) {
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_57) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_58) {
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_59) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_60) {
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_61) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_62) {
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_63) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_64) {
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_65) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_66) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_67) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_68) {
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_69) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_70) {
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_71) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_72) {
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_73) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_74) {
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_75) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_76) {
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_77) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_78) {
  s21_decimal decimal1 = {{0, 0, 0, 10 << 16}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  int check = 0;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_79) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

START_TEST(test_is_not_equal_80) {
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int code = s21_is_not_equal(decimal1, decimal2);
  ck_assert_int_eq(code, check);
}

Suite *suite_is_not_equal(void) {
  Suite *suite = suite_create("\033[30;43m S21_IS_NOT_EQUAL \033[0m");
  TCase *tc = tcase_create("tcase_is_not_equal");

  tcase_add_test(tc, test_is_not_equal_1);
  tcase_add_test(tc, test_is_not_equal_2);
  tcase_add_test(tc, test_is_not_equal_3);
  tcase_add_test(tc, test_is_not_equal_4);
  tcase_add_test(tc, test_is_not_equal_5);
  tcase_add_test(tc, test_is_not_equal_6);
  tcase_add_test(tc, test_is_not_equal_7);
  tcase_add_test(tc, test_is_not_equal_8);
  tcase_add_test(tc, test_is_not_equal_9);
  tcase_add_test(tc, test_is_not_equal_10);
  tcase_add_test(tc, test_is_not_equal_11);
  tcase_add_test(tc, test_is_not_equal_12);
  tcase_add_test(tc, test_is_not_equal_13);
  tcase_add_test(tc, test_is_not_equal_14);
  tcase_add_test(tc, test_is_not_equal_15);
  tcase_add_test(tc, test_is_not_equal_16);
  tcase_add_test(tc, test_is_not_equal_17);
  tcase_add_test(tc, test_is_not_equal_18);
  tcase_add_test(tc, test_is_not_equal_19);
  tcase_add_test(tc, test_is_not_equal_20);
  tcase_add_test(tc, test_is_not_equal_21);
  tcase_add_test(tc, test_is_not_equal_22);
  tcase_add_test(tc, test_is_not_equal_23);
  tcase_add_test(tc, test_is_not_equal_24);
  tcase_add_test(tc, test_is_not_equal_25);
  tcase_add_test(tc, test_is_not_equal_26);
  tcase_add_test(tc, test_is_not_equal_27);
  tcase_add_test(tc, test_is_not_equal_28);
  tcase_add_test(tc, test_is_not_equal_29);
  tcase_add_test(tc, test_is_not_equal_30);
  tcase_add_test(tc, test_is_not_equal_31);
  tcase_add_test(tc, test_is_not_equal_32);
  tcase_add_test(tc, test_is_not_equal_33);
  tcase_add_test(tc, test_is_not_equal_34);
  tcase_add_test(tc, test_is_not_equal_35);
  tcase_add_test(tc, test_is_not_equal_36);
  tcase_add_test(tc, test_is_not_equal_37);
  tcase_add_test(tc, test_is_not_equal_38);
  tcase_add_test(tc, test_is_not_equal_39);
  tcase_add_test(tc, test_is_not_equal_40);
  tcase_add_test(tc, test_is_not_equal_41);
  tcase_add_test(tc, test_is_not_equal_42);
  tcase_add_test(tc, test_is_not_equal_43);
  tcase_add_test(tc, test_is_not_equal_44);
  tcase_add_test(tc, test_is_not_equal_45);
  tcase_add_test(tc, test_is_not_equal_46);
  tcase_add_test(tc, test_is_not_equal_47);
  tcase_add_test(tc, test_is_not_equal_48);
  tcase_add_test(tc, test_is_not_equal_49);
  tcase_add_test(tc, test_is_not_equal_50);
  tcase_add_test(tc, test_is_not_equal_51);
  tcase_add_test(tc, test_is_not_equal_52);
  tcase_add_test(tc, test_is_not_equal_53);
  tcase_add_test(tc, test_is_not_equal_54);
  tcase_add_test(tc, test_is_not_equal_55);
  tcase_add_test(tc, test_is_not_equal_56);
  tcase_add_test(tc, test_is_not_equal_57);
  tcase_add_test(tc, test_is_not_equal_58);
  tcase_add_test(tc, test_is_not_equal_59);
  tcase_add_test(tc, test_is_not_equal_60);
  tcase_add_test(tc, test_is_not_equal_61);
  tcase_add_test(tc, test_is_not_equal_62);
  tcase_add_test(tc, test_is_not_equal_63);
  tcase_add_test(tc, test_is_not_equal_64);
  tcase_add_test(tc, test_is_not_equal_65);
  tcase_add_test(tc, test_is_not_equal_66);
  tcase_add_test(tc, test_is_not_equal_67);
  tcase_add_test(tc, test_is_not_equal_68);
  tcase_add_test(tc, test_is_not_equal_69);
  tcase_add_test(tc, test_is_not_equal_70);
  tcase_add_test(tc, test_is_not_equal_71);
  tcase_add_test(tc, test_is_not_equal_72);
  tcase_add_test(tc, test_is_not_equal_73);
  tcase_add_test(tc, test_is_not_equal_74);
  tcase_add_test(tc, test_is_not_equal_75);
  tcase_add_test(tc, test_is_not_equal_76);
  tcase_add_test(tc, test_is_not_equal_77);
  tcase_add_test(tc, test_is_not_equal_78);
  tcase_add_test(tc, test_is_not_equal_79);
  tcase_add_test(tc, test_is_not_equal_80);

  suite_add_tcase(suite, tc);
  return suite;
}
