#include "s21_big_decimal.h"

bool s21_is_zero(s21_decimal value) {
  bool is_zero = 1;
  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(value, i)) {
      is_zero = 0;
      break;
    }
  }
  return is_zero;
}

bool s21_get_bit(s21_decimal value, unsigned index) {
  int byte = index / 32;
  index %= 32;
  return (value.bits[byte]) & (1 << index);
}

void s21_set_bit(s21_decimal *value, unsigned index, int bit) {
  int byte = index / 32;
  index %= 32;
  if (bit == 0) {
    value->bits[byte] &= ~(1 << index);
  } else {
    value->bits[byte] |= (1 << index);
  }
}

bool s21_get_sign(s21_decimal value) { return s21_get_bit(value, 32 * 4 - 1); }

void s21_set_sign(s21_decimal *value, int sign) {
  int tmp = 0b11111111 & value->bits[3];
  unsigned short scale = s21_get_scale(*value);
  value->bits[3] = (sign << 31) | (scale << 16);
  value->bits[3] |= tmp;
}

int s21_get_scale(s21_decimal value) {
  int mask = 0b1111111;
  return ((value.bits[3] >> 16) & mask);
}

void s21_set_scale(s21_decimal *value, int scale) {
  int tmp = 0b11111111 & value->bits[3];
  unsigned short sign = s21_get_sign(*value);
  value->bits[3] = (sign << 31) | (scale << 16);
  value->bits[3] |= tmp;
}
