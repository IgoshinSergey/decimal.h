#include "../s21_big_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 1;
  if (result) {
    bool sign = s21_get_sign(value);
    sign = (sign) ? 0 : 1;
    s21_set_sign(&value, sign);
    *result = value;
  } else {
    res = 0;
  }
  return res;
}
