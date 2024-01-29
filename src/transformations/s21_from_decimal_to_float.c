#include "../s21_big_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  if (!dst) {
    res = 1;
  } else if (s21_is_zero(src)) {
    *dst = 0.;
  } else {
    bool sign = s21_get_sign(src);
    int scale = s21_get_scale(src);
    double tmp = 0.;
    for (int i = 0; i < 32 * 3; i++) {
      if (s21_get_bit(src, i)) tmp += pow(2., i);
    }
    if (scale > 0) tmp /= pow(10., scale);
    if (sign) tmp *= -1.;
    *dst = (float)tmp;
  }
  return res;
}
