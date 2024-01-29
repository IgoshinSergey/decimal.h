#ifndef C5_S21_DECIMAL_1_S21_DECIMAL_H_
#define C5_S21_DECIMAL_1_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*===== Limit Values =====*/
#define DECIMAL_MAX (s21_decimal) {{ 0xffffffff, 0xffffffff, 0xffffffff, 0 }}
#define DECIMAL_MIN (s21_decimal) {{ 0xffffffff, 0xffffffff, 0xffffffff, 0b1 << 31 }}

typedef struct {
  unsigned bits[4];
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);

int s21_from_float_to_decimal(float src, s21_decimal *dst);

int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);

int s21_round(s21_decimal value, s21_decimal *result);

int s21_truncate(s21_decimal value, s21_decimal *result);

int s21_negate(s21_decimal value, s21_decimal *result);

/*Вспомогательные функции*/

bool s21_is_zero(s21_decimal value);
bool s21_get_bit(s21_decimal value, unsigned index);
void s21_set_bit(s21_decimal *value, unsigned index, int bit);
bool s21_get_sign(s21_decimal value);
void s21_set_sign(s21_decimal *value, int sign);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int scale);

#endif  // C5_S21_DECIMAL_1_S21_DECIMAL_H_
