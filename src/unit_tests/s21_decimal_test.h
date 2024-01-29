#ifndef C2_S21_DECIMAL_UNIT_TESTS_S21_DECIMAL_TEST_H_
#define C2_S21_DECIMAL_UNIT_TESTS_S21_DECIMAL_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_big_decimal.h"

#define SUCCESS 0
#define FALSE 0
#define TRUE 1

Suite *suite_sub(void);
Suite *suite_div(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_not_equal(void);
Suite *suite_negate(void);
Suite *suite_round(void);
Suite *suite_from_decimal_to_float(void);
Suite *suite_from_float_to_decimal(void);
Suite *suite_add(void);
Suite *suite_mul(void);
Suite *suite_is_less(void);
Suite *suite_is_greater(void);
Suite *suite_is_equal(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_floor(void);
Suite *suite_truncate(void);

#endif  // C2_S21_DECIMAL_UNIT_TESTS_S21_DECIMAL_TEST_H_
