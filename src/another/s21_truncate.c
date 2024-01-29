#include "../s21_big_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result) {
    s21_big_decimal tmp = s21_decimal_to_big_decimal(value);
    int scale = s21_get_scale_big(tmp);
    bool sign = s21_get_sign_big(tmp);
    s21_big_decimal ten = BIG_DEC_TEN;
    for (int i = 1; i < scale; i++) s21_mul_ten_big(&ten);
    s21_mantissa_div_big(tmp, ten, &tmp);
    s21_set_sign_big(&tmp, sign);
    *result = value;
  } else {
    res = 1;
  }
  return res;
}
