# s21_decimal

Реализация собственной библиотеки s21_decimal.h.

## Information

Тип Decimal представляет десятичные числа в диапазоне от положительных 79,228,162,514,264,337,593,543,950,335 до отрицательных 79,228,162,514,264,337,593,543,950,335. Значение Decimal по умолчанию равно 0. Decimal подходит для финансовых расчетов, которые требуют большого количества значимых целых и дробных цифр и отсутствия ошибок округления. Этот тип не устраняет необходимость округления. Скорее, сводит к минимуму количество ошибок из-за округления.

Когда результат деления и умножения передается методу округления, результат не страдает от потери точности.

Decimal число - это значение с плавающей точкой, состоящее из знака, числового значения, где каждая цифра находится в диапазоне от 0 до 9, и коэффициента масштабирования, который указывает положение десятичной точки, разделяющей целые и дробные части числового значения.

Двоичное представление Decimal состоит из 1-разрядного знака, 96-разрядного целого числа и коэффициента масштабирования, используемого для деления 96-разрядного целого числа и указания того, какая его часть является десятичной дробью. Коэффициент масштабирования неявно равен числу 10, возведенному в степень в диапазоне от 0 до 28. Следовательно, двоичное представление Decimal имеет вид ((от -2^96 до 2^96) / 10^(от 0 до 28)), где -(2^96-1) равно минимальному значению, а 2^96-1 равно максимальному значению.

Коэффициент масштабирования также может сохранять любые конечные нули в Decimal. Эти конечные нули не влияют на значение в арифметических операциях или операциях сравнения. 

### Двоичное представление  

Двоичное представление Decimal состоит из 1-разрядного знака, 96-разрядного целого числа и коэффициента масштабирования, используемого для деления целого числа и указания того, какая его часть является десятичной дробью. Коэффициент масштабирования неявно равен числу 10, возведенному в степень в диапазоне от 0 до 28.

Decimal число может быть реализовано в виде четырехэлементного массива 32-разрядных целых чисел со знаком (`int bits[4];`).

`bits[0]`, `bits[1]`, и `bits[2]` содержат младшие, средние и старшие 32 бита 96-разрядного целого числа соответственно.

`bits[3]` содержит коэффициент масштабирования и знак, и состоит из следующих частей:
- Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
- Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который указывает степень 10 для разделения целого числа.
- Биты с 24 по 30 не используются и должны быть равны нулю.
- Бит 31 содержит знак; 0 означает положительный, а 1 означает отрицательный.

Обратите внимание, что битовое представление различает отрицательные и положительные нули. Эти значения могут считаться эквивалентными во всех операциях.

### Пример:

```c
typedef struct 
{
    int bits[4];
} s21_decimal;
```

### Арифметические операторы

| Название оператора | Оператор  | Функция                                                                            | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Сложение | + | int s21_add(s21_decimal val_1, s21_decimal val_2, s21_decimal *result)         |
| Вычитание | - | int s21_sub(s21_decimal val_1, s21_decimal val_2, s21_decimal *result)         |
| Умножение | * | int s21_mul(s21_decimal val_1, s21_decimal val_2, s21_decimal *result) | 
| Деление | / | int s21_div(s21_decimal val_1, s21_decimal val_2, s21_decimal *result) |

Функции возвращают код ошибки:
- 0 - OK  
- 1 - число слишком велико или равно бесконечности
- 2 - число слишком мало или равно отрицательной бесконечности
- 3 - деление на 0

*Уточнение про числа, не вмещающиеся в мантиссу:*
- *При получении чисел, не вмещающихся в мантиссу при арифметических операциях, использовать банковское округление (например, 79,228,162,514,264,337,593,543,950,335 - 0.5 = 79,228,162,514,264,337,593,543,950,334)*


### Операторы сравнение

| Название оператора | Оператор  | Функция | 
| ------ | ------ | ------ |
| Меньше  | < | int s21_is_less(s21_decimal, s21_decimal) |
| Меньше или равно | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Больше | \> |  int s21_is_greater(s21_decimal, s21_decimal) |
| Больше или равно | \>= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Равно | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Не равно | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Возвращаемое значение:
- 0 - FALSE
- 1 - TRUE

### Преобразователи 

| Преобразователь | Функция | 
| ------ | ------ |
| Из int | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| Из float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| В int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| В float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка конвертации

### Другие функции

| Описание | Функция                                                  | 
| ------ |----------------------------------------------------------|
| Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности. | int s21_floor(s21_decimal value, s21_decimal *result)    |	
| Округляет Decimal до ближайшего целого числа. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Возвращает результат умножения указанного Decimal на -1. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка вычисления

### Build

Сборка библиотеки настроена с помощью Makefile

* `make s21_decimal.a` - Сборка библиотеки s21_decimal.a
* `make test` - Покрытие unit-тестами функций библиотеки c помощью библиотеки Check
* `make gcov_report` - Формирование отчёта gcov в виде html страницы
* `make leaks` - Проверка тестов на утечки памяти (Linux - valgrind, MacOS - leaks)
* `make clang` - Проверка кода на Google style
* `make clean` - Удаление ненужных файлов

Реализация функции библиотеки decimal.h

- Библиотека разработана на языке С стандарта C11 с использованием компиятора gcc;
- Решение оформлено как статическая библиотека с названием s21_decimal.a (с заголовочным файлом s21_decimal.h);
- Библиотека разработана в соответствии с принципами структурного программирования;
- Полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;
- Формирование отчёта gcov в виде html страницы.
- Определяемый тип поддерживает числа от -79,228,162,514,264,337,593,543,950,335 до +79,228,162,514,264,337,593,543,950,335.
