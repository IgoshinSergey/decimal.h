#include "../s21_big_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  if (src == 0.) {
    *dst = DECIMAL_ZERO;
  } else if (fabsf(src) > MAX_FLOAT) {
    res = 1;
  } else if (fabsf(src) < MIN_FLOAT) {
    res = 1;
    *dst = DECIMAL_ZERO;
  } else {
    s21_big_decimal tmp = {0};
    char str[100];
    sprintf(str, "%.6e", src);
    s21_big_decimal ten = BIG_DEC_TEN;
    for (int i = 1; i < 7; i++) s21_mul_ten_big(&ten);
    int i = 0, k = 6;
    while (str[i] != 'e') {
      if (s21_is_digit(str[i])) {
        int symbol = s21_symbol_to_int(str[i]);
        s21_big_decimal digit = {0};
        digit.bits[0] = symbol;
        for (int j = 0; j < k; j++) s21_mul_ten_big(&digit);
        s21_mantissa_add_big(tmp, digit, &tmp);
        k--;
      }
      s21_shift_right_big(&ten, 1);
      i++;
    }
    int scale = s21_get_scale_from_str((char *)(str + i + 1));
    scale = 6 - scale;
    bool sign = (src < 0.) ? 1 : 0;
    s21_big_decimal remainder = s21_mantissa_div_big(tmp, BIG_DEC_TEN, NULL);
    while (s21_is_zero_big(remainder) && scale > 0) {
      s21_mantissa_div_big(tmp, BIG_DEC_TEN, &tmp);
      scale--;
      remainder = s21_mantissa_div_big(tmp, BIG_DEC_TEN, NULL);
    }
    while (scale < 0) {
      s21_mul_ten_big(&tmp);
      scale++;
    }
    s21_delete_zero_big(&tmp);
    s21_set_scale_big(&tmp, scale);
    s21_set_sign_big(&tmp, sign);
    *dst = s21_big_decimal_to_decimal(tmp);
  }
  return res;
}

int s21_is_digit(char symbol) {
  int res = (symbol >= '0' && symbol <= '9');
  return res;
}

int s21_symbol_to_int(char symbol) {
  int res = symbol - '0';
  return res;
}

int s21_get_scale_from_str(char *str) {
  char *endptr;
  int res = strtol(str, &endptr, 10);
  return res;
}