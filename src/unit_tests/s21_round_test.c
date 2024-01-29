#include "s21_decimal_test.h"

START_TEST(test_round_1) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_2) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_3) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_4) {
  // -7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395034
  s21_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_5) {
  // 792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_6) {
  // -792281625142643375935439503.35
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_7) {
  // 79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_8) {
  // -79228162514264337593543950.335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_9) {
  // 7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_10) {
  // -7922816251426433759354395.0335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_11) {
  // 792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_12) {
  // -792281625142643375935439.50335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_13) {
  // 79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_14) {
  // -79228162514264337593543.950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_15) {
  // 7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_16) {
  // -7922816251426433759354.3950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_17) {
  // 792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_18) {
  // -792281625142643375935.43950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  // -792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_19) {
  // 79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  // 79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_20) {
  // -79228162514264337593.543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  // -79228162514264337594
  s21_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_21) {
  // 7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  // 7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_22) {
  // -7922816251426433759.3543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  // -7922816251426433759
  s21_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_23) {
  // 792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  // 792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_24) {
  // -792281625142643375.93543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  // -792281625142643376
  s21_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_25) {
  // 79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // 79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_26) {
  // -79228162514264337.593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  // -79228162514264338
  s21_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_27) {
  // 7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  // 7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_28) {
  // -7922816251426433.7593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  // -7922816251426434
  s21_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_29) {
  // 792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  // 792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_30) {
  // -792281625142643.37593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  // -792281625142643
  s21_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_31) {
  // 79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  // 79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_32) {
  // -79228162514264.337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  // -79228162514264
  s21_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_33) {
  // 7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  // 7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_34) {
  // -7922816251426.4337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  // -7922816251426
  s21_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_35) {
  // 792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  // 792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_36) {
  // -792281625142.64337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  // -792281625143
  s21_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_37) {
  // 79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  // 79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_38) {
  // -79228162514.264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  // -79228162514
  s21_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_39) {
  // 7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  // 7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_40) {
  // -7922816251.4264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  // -7922816251
  s21_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_41) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  // 792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_42) {
  // -792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  // -792281625
  s21_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_43) {
  // 79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  // 79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_44) {
  // -79228162.514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  // -79228163
  s21_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_45) {
  // 7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  // 7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_46) {
  // -7922816.2514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  // -7922816
  s21_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_47) {
  // 792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  // 792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_48) {
  // -792281.62514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  // -792282
  s21_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_49) {
  // 79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  // 79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_50) {
  // -79228.162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  // -79228
  s21_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_51) {
  // 7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  // 7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_52) {
  // -7922.8162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  // -7923
  s21_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_53) {
  // 792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  // 792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_54) {
  // -792.28162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  // -792
  s21_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_55) {
  // 79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  // 79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_56) {
  // -79.228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  // -79
  s21_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_57) {
  // 7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_58) {
  // -7.9228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -8
  s21_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_59) {
  // 79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  s21_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_60) {
  // -79228162514264337593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  s21_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_61) {
  // 7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395033
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_62) {
  // -7922816251426433759354395033.4
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -7922816251426433759354395033
  s21_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_63) {
  // 792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  // 792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_64) {
  // -792281625142643375935439503.34
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  // -792281625142643375935439503
  s21_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_65) {
  // 79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  // 79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_66) {
  // -79228162514264337593543950.334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  // -79228162514264337593543950
  s21_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_67) {
  // 7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  // 7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_68) {
  // -7922816251426433759354395.0334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  // -7922816251426433759354395
  s21_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_69) {
  // 792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  // 792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_70) {
  // -792281625142643375935439.50334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  // -792281625142643375935440
  s21_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_71) {
  // 79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  // 79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_72) {
  // -79228162514264337593543.950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  // -79228162514264337593544
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_73) {
  // 7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  // 7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_74) {
  // -7922816251426433759354.3950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  // -7922816251426433759354
  s21_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_75) {
  // 792281625142643375935.43950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  // 792281625142643375935
  s21_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_76) {
  // -2.5
  s21_decimal decimal = {{25, 0, 0, (1 << 31) | (1 << 16)}};
  // -2
  s21_decimal decimal_check = {{2, 0, 0, (1 << 31)}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_77) {
  // -0.5000000000000000000000000000
  s21_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_78) {
  // 0.5
  s21_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_79) {
  // 429496729.5
  s21_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};
  // 429496730
  s21_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_80) {
  // 7922816251426433759354395033.5
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // 7922816251426433759354395034
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(test_round_81) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  s21_decimal *result = NULL;
  int res = s21_round(decimal, result);
  ck_assert_int_eq(res, 1);
}

Suite *suite_round(void) {
  Suite *suite = suite_create("\033[30;43m S21_ROUND \033[0m");
  TCase *tc = tcase_create("tcase_round");

  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);
  tcase_add_test(tc, test_round_8);
  tcase_add_test(tc, test_round_9);
  tcase_add_test(tc, test_round_10);
  tcase_add_test(tc, test_round_11);
  tcase_add_test(tc, test_round_12);
  tcase_add_test(tc, test_round_13);
  tcase_add_test(tc, test_round_14);
  tcase_add_test(tc, test_round_15);
  tcase_add_test(tc, test_round_16);
  tcase_add_test(tc, test_round_17);
  tcase_add_test(tc, test_round_18);
  tcase_add_test(tc, test_round_19);
  tcase_add_test(tc, test_round_20);
  tcase_add_test(tc, test_round_21);
  tcase_add_test(tc, test_round_22);
  tcase_add_test(tc, test_round_23);
  tcase_add_test(tc, test_round_24);
  tcase_add_test(tc, test_round_25);
  tcase_add_test(tc, test_round_26);
  tcase_add_test(tc, test_round_27);
  tcase_add_test(tc, test_round_28);
  tcase_add_test(tc, test_round_29);
  tcase_add_test(tc, test_round_30);
  tcase_add_test(tc, test_round_31);
  tcase_add_test(tc, test_round_32);
  tcase_add_test(tc, test_round_33);
  tcase_add_test(tc, test_round_34);
  tcase_add_test(tc, test_round_35);
  tcase_add_test(tc, test_round_36);
  tcase_add_test(tc, test_round_37);
  tcase_add_test(tc, test_round_38);
  tcase_add_test(tc, test_round_39);
  tcase_add_test(tc, test_round_40);
  tcase_add_test(tc, test_round_41);
  tcase_add_test(tc, test_round_42);
  tcase_add_test(tc, test_round_43);
  tcase_add_test(tc, test_round_44);
  tcase_add_test(tc, test_round_45);
  tcase_add_test(tc, test_round_46);
  tcase_add_test(tc, test_round_47);
  tcase_add_test(tc, test_round_48);
  tcase_add_test(tc, test_round_49);
  tcase_add_test(tc, test_round_50);
  tcase_add_test(tc, test_round_51);
  tcase_add_test(tc, test_round_52);
  tcase_add_test(tc, test_round_53);
  tcase_add_test(tc, test_round_54);
  tcase_add_test(tc, test_round_55);
  tcase_add_test(tc, test_round_56);
  tcase_add_test(tc, test_round_57);
  tcase_add_test(tc, test_round_58);
  tcase_add_test(tc, test_round_59);
  tcase_add_test(tc, test_round_60);
  tcase_add_test(tc, test_round_61);
  tcase_add_test(tc, test_round_62);
  tcase_add_test(tc, test_round_63);
  tcase_add_test(tc, test_round_64);
  tcase_add_test(tc, test_round_65);
  tcase_add_test(tc, test_round_66);
  tcase_add_test(tc, test_round_67);
  tcase_add_test(tc, test_round_68);
  tcase_add_test(tc, test_round_69);
  tcase_add_test(tc, test_round_70);
  tcase_add_test(tc, test_round_71);
  tcase_add_test(tc, test_round_72);
  tcase_add_test(tc, test_round_73);
  tcase_add_test(tc, test_round_74);
  tcase_add_test(tc, test_round_75);
  tcase_add_test(tc, test_round_76);
  tcase_add_test(tc, test_round_77);
  tcase_add_test(tc, test_round_78);
  tcase_add_test(tc, test_round_79);
  tcase_add_test(tc, test_round_80);
  tcase_add_test(tc, test_round_81);

  suite_add_tcase(suite, tc);

  return suite;
}
