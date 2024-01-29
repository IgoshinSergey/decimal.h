#include "../s21_big_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result) {
    s21_big_decimal tmp = s21_decimal_to_big_decimal(value);
    int scale = s21_get_scale_big(tmp);
    bool sign = s21_get_sign_big(tmp);
    s21_big_decimal ten = BIG_DEC_TEN;
    for (int i = 1; i < scale; i++) {
      s21_mul_ten_big(&ten);
    }
    s21_big_decimal remainder = s21_mantissa_div_big(tmp, ten, &tmp);
    if (!s21_is_zero_big(remainder)) {
      if (sign == 1) {
        s21_mantissa_add_big(tmp, BIG_DEC_ONE, &tmp);
      }
    }
    s21_set_sign_big(&tmp, sign);
    s21_set_scale_big(&tmp, scale);
    *result = value;
  } else {
    res = 1;
  }
  return res;
}