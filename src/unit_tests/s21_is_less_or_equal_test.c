#include "s21_decimal_test.h"

START_TEST(test_is_less_or_equal_1) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_2) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_3) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_4) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_6) {
  // 52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966890
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_8) {
  // -52818775009509558395695966890
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_10) {
  // 52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_11) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -52818775009509558395695966891
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_12) {
  // -52818775009509558395695966891
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_13) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_14) {
  // 5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x1B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_15) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5.281877500950955839569596690
  s21_decimal decimal2 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_16) {
  // -5.281877500950955839569596690
  s21_decimal decimal1 = {{0x11111112, 0x11111111, 0x11111111, 0x801B0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_17) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_18) {
  // 5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_19) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689
  s21_decimal decimal2 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_20) {
  // -5281877500950955839569596689
  s21_decimal decimal1 = {{0x11111111, 0x11111111, 0x11111111, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_21) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_22) {
  // 5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_23) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -5281877500950955839569596689.0
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_24) {
  // -5281877500950955839569596689.0
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_25) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_26) {
  // 7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_27) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  s21_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_28) {
  // -7922816251426433759354395033
  s21_decimal decimal1 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_29) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_30) {
  // 7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_31) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395034
  s21_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_32) {
  // -7922816251426433759354395034
  s21_decimal decimal1 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_33) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_34) {
  // 1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_35) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034409
  s21_decimal decimal2 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_36) {
  // -1.2297829382473034409
  s21_decimal decimal1 = {{0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_37) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_38) {
  // 1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_39) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034410
  s21_decimal decimal2 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_40) {
  // -1.2297829382473034410
  s21_decimal decimal1 = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_41) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_42) {
  // 1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_43) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.2297829382473034411
  s21_decimal decimal2 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_44) {
  // -1.2297829382473034411
  s21_decimal decimal1 = {{0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_45) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_46) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_47) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_48) {
  // -1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_49) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_50) {
  // 1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_51) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.0
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_52) {
  // -1.0
  s21_decimal decimal1 = {{0xA, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_53) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x20000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_54) {
  // 1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x20000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_55) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.22
  s21_decimal decimal2 = {{0x7A, 0x0, 0x0, 0x80020000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_56) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_57) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_58) {
  // 1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x60000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_59) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.230001
  s21_decimal decimal2 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_60) {
  // -1.230001
  s21_decimal decimal1 = {{0x12C4B1, 0x0, 0x0, 0x80060000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_61) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x50000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_62) {
  // 1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_63) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1.23000
  s21_decimal decimal2 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_64) {
  // -1.23000
  s21_decimal decimal1 = {{0x1E078, 0x0, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_65) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_66) {
  // 1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_67) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_68) {
  // -1431655765
  s21_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_69) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_70) {
  // 1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x50000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_71) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.00000
  s21_decimal decimal2 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_72) {
  // -1431655765.00000
  s21_decimal decimal1 = {{0x5554D320, 0x8235, 0x0, 0x80050000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_73) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_74) {
  // 1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_75) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655765.000000000000000001
  s21_decimal decimal2 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_76) {
  // -1431655765.000000000000000001
  s21_decimal decimal1 = {{0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_77) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_78) {
  // 1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_79) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -1431655764.999999999999999999
  s21_decimal decimal2 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_80) {
  // -1431655764.999999999999999999
  s21_decimal decimal1 = {{0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_81) {
  // 0
  s21_decimal decimal1 = {{0, 0, 0, 10 << 16}};
  // 0
  s21_decimal decimal2 = {{0, 0, 0, 20 << 16}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_82) {
  // -9
  s21_decimal decimal1 = {{9, 0, 0, 1 << 31}};
  // -10
  s21_decimal decimal2 = {{10, 0, 0, 1 << 31}};
  int check = 0;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

START_TEST(test_is_less_or_equal_83) {
  // -11
  s21_decimal decimal1 = {{11, 0, 0, 1 << 31}};
  // -10
  s21_decimal decimal2 = {{10, 0, 0, 1 << 31}};
  int check = 1;
  int result = s21_is_less_or_equal(decimal1, decimal2);
  ck_assert_int_eq(result, check);
}

Suite *suite_is_less_or_equal(void) {
  Suite *suite = suite_create("\033[30;43m SUITE_IS_LESS_OR_EQUAL \033[0m");
  TCase *tc = tcase_create("tcase_is_less_or_equal");

  tcase_add_test(tc, test_is_less_or_equal_1);
  tcase_add_test(tc, test_is_less_or_equal_2);
  tcase_add_test(tc, test_is_less_or_equal_3);
  tcase_add_test(tc, test_is_less_or_equal_4);
  tcase_add_test(tc, test_is_less_or_equal_5);
  tcase_add_test(tc, test_is_less_or_equal_6);
  tcase_add_test(tc, test_is_less_or_equal_7);
  tcase_add_test(tc, test_is_less_or_equal_8);
  tcase_add_test(tc, test_is_less_or_equal_9);
  tcase_add_test(tc, test_is_less_or_equal_10);
  tcase_add_test(tc, test_is_less_or_equal_11);
  tcase_add_test(tc, test_is_less_or_equal_12);
  tcase_add_test(tc, test_is_less_or_equal_13);
  tcase_add_test(tc, test_is_less_or_equal_14);
  tcase_add_test(tc, test_is_less_or_equal_15);
  tcase_add_test(tc, test_is_less_or_equal_16);
  tcase_add_test(tc, test_is_less_or_equal_17);
  tcase_add_test(tc, test_is_less_or_equal_18);
  tcase_add_test(tc, test_is_less_or_equal_19);
  tcase_add_test(tc, test_is_less_or_equal_20);
  tcase_add_test(tc, test_is_less_or_equal_21);
  tcase_add_test(tc, test_is_less_or_equal_22);
  tcase_add_test(tc, test_is_less_or_equal_23);
  tcase_add_test(tc, test_is_less_or_equal_24);
  tcase_add_test(tc, test_is_less_or_equal_25);
  tcase_add_test(tc, test_is_less_or_equal_26);
  tcase_add_test(tc, test_is_less_or_equal_27);
  tcase_add_test(tc, test_is_less_or_equal_28);
  tcase_add_test(tc, test_is_less_or_equal_29);
  tcase_add_test(tc, test_is_less_or_equal_30);
  tcase_add_test(tc, test_is_less_or_equal_31);
  tcase_add_test(tc, test_is_less_or_equal_32);
  tcase_add_test(tc, test_is_less_or_equal_33);
  tcase_add_test(tc, test_is_less_or_equal_34);
  tcase_add_test(tc, test_is_less_or_equal_35);
  tcase_add_test(tc, test_is_less_or_equal_36);
  tcase_add_test(tc, test_is_less_or_equal_37);
  tcase_add_test(tc, test_is_less_or_equal_38);
  tcase_add_test(tc, test_is_less_or_equal_39);
  tcase_add_test(tc, test_is_less_or_equal_40);
  tcase_add_test(tc, test_is_less_or_equal_41);
  tcase_add_test(tc, test_is_less_or_equal_42);
  tcase_add_test(tc, test_is_less_or_equal_43);
  tcase_add_test(tc, test_is_less_or_equal_44);
  tcase_add_test(tc, test_is_less_or_equal_45);
  tcase_add_test(tc, test_is_less_or_equal_46);
  tcase_add_test(tc, test_is_less_or_equal_47);
  tcase_add_test(tc, test_is_less_or_equal_48);
  tcase_add_test(tc, test_is_less_or_equal_49);
  tcase_add_test(tc, test_is_less_or_equal_50);
  tcase_add_test(tc, test_is_less_or_equal_51);
  tcase_add_test(tc, test_is_less_or_equal_52);
  tcase_add_test(tc, test_is_less_or_equal_53);
  tcase_add_test(tc, test_is_less_or_equal_54);
  tcase_add_test(tc, test_is_less_or_equal_55);
  tcase_add_test(tc, test_is_less_or_equal_56);
  tcase_add_test(tc, test_is_less_or_equal_57);
  tcase_add_test(tc, test_is_less_or_equal_58);
  tcase_add_test(tc, test_is_less_or_equal_59);
  tcase_add_test(tc, test_is_less_or_equal_60);
  tcase_add_test(tc, test_is_less_or_equal_61);
  tcase_add_test(tc, test_is_less_or_equal_62);
  tcase_add_test(tc, test_is_less_or_equal_63);
  tcase_add_test(tc, test_is_less_or_equal_64);
  tcase_add_test(tc, test_is_less_or_equal_65);
  tcase_add_test(tc, test_is_less_or_equal_66);
  tcase_add_test(tc, test_is_less_or_equal_67);
  tcase_add_test(tc, test_is_less_or_equal_68);
  tcase_add_test(tc, test_is_less_or_equal_69);
  tcase_add_test(tc, test_is_less_or_equal_70);
  tcase_add_test(tc, test_is_less_or_equal_71);
  tcase_add_test(tc, test_is_less_or_equal_72);
  tcase_add_test(tc, test_is_less_or_equal_73);
  tcase_add_test(tc, test_is_less_or_equal_74);
  tcase_add_test(tc, test_is_less_or_equal_75);
  tcase_add_test(tc, test_is_less_or_equal_76);
  tcase_add_test(tc, test_is_less_or_equal_77);
  tcase_add_test(tc, test_is_less_or_equal_78);
  tcase_add_test(tc, test_is_less_or_equal_79);
  tcase_add_test(tc, test_is_less_or_equal_80);
  tcase_add_test(tc, test_is_less_or_equal_81);
  tcase_add_test(tc, test_is_less_or_equal_82);
  tcase_add_test(tc, test_is_less_or_equal_83);

  suite_add_tcase(suite, tc);
  return suite;
}
