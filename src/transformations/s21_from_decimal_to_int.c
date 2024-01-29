#include "../s21_big_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0, res = 0, is_neg = 0;
  if (!s21_is_zero(src)) {
    if (s21_get_sign(src)) is_neg = 1;
    s21_truncate(src, &src);
    if (src.bits[1] == 0 && src.bits[2] == 0) {
      for (int i = 0; i < 32; i++) {
        if (s21_get_bit(src, i)) res += pow(2, i);
      }
    } else {
      error = 1;
    }
  }
  if (error == 0) {
    *dst = res;
    if (is_neg) {
      *dst *= -1;
    }
  }
  return error;
}
