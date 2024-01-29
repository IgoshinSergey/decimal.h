#include "../s21_big_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  s21_decimal res = {0};
  if (src) {
    if (src < 0) s21_set_sign(&res, 1);
    for (int i = 0; i < 96; i++) {
      s21_set_bit(&res, i, src % 2);
      src /= 2;
      if (!src) {
        break;
      }
    }
  }
  if (error == 0) *dst = res;
  return error;
}