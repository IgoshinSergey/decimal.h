#include "../s21_big_decimal.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  s21_big_decimal v1 = s21_decimal_to_big_decimal(value_1);
  s21_big_decimal v2 = s21_decimal_to_big_decimal(value_2);
  s21_normalization(&v1, &v2);
  bool sign1 = s21_get_sign_big(v1);
  bool sign2 = s21_get_sign_big(v2);
  if (s21_is_zero_big(v1) && s21_is_zero_big(v2)) {
    res = 1;
  } else if (sign1 == 1 && sign2 == 0) {
    res = 1;
  } else if (sign1 == sign2) {
    if (sign1 == 0) {
      res = (s21_mantissa_comparison(v1, v2) >= 0) ? 1 : 0;
    } else {
      res = (s21_mantissa_comparison(v1, v2) <= 0) ? 1 : 0;
    }
  }
  return res;
}
