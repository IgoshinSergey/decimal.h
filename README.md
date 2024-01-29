# s21_decimal

Реализация собственной библиотеки s21_decimal.h.

Вернуться на [страницу профиля](https://github.com/IgoshinSergey)

## Contents
1. [Сборка проекта](#Сборка-библиотеки) \
    1.1 [Примеры использования](#примеры-использавния)
2. [Chapter I](#chapter-i) \
    2.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    3.1. [Information](#information)

## Сборка библиотеки

```bash
git clone https://github.com/IgoshinSergey/decimal.h.git
make s21_decimal.a # сборка библиотеки
make test          # unit-тестирование
make gcov_report   # отчет gcov в виде html страницы
```
### Примеры использавния:
Функция s21_add:
```C
// value_1: мантисса 123456, знак -, коэффициент масштабирования 3
// -123.456
s21_decimal value_1 = {{123456, 0, 0, 1 << 31 | 3 << 16}};

// value_2: мантисса 654321, знак +, коэффициент масштабирования 4
// 6543.21
s21_decimal value_2 = {{654321, 0, 0, 4 << 16}};

s21_decimal result = {0};
s21_add(value_1, value_2, &result);
// result: мантисса 580239, знак -, коэффициент масштабирования 4
// -58.0239
```
## Chapter I

![s21_decimal](misc/images/s21_decimal.png)

Планета Земля, 90 годы 

Мировая экономика растёт экспоненциально, биржа увеличивается многократно из года в год, все больше и больше компаний выходят на IPO и их акции начинают котироваться. Число пользователей, количество транзакций, цена, комиссия, проценты, расчёт финансовых технических индикаторов... Важность точности всех этих данных сложно переоценить, а с текущими устаревшими типами данных, которые используются в финансовом секторе, возникают серьёзные проблемы. 

Из-за погрешности вычисления в обычном IEEE 754 (float) за год теряются миллионы долларов, которые просто абсорбируются из системы, пропадая навсегда. 

Вместе с разрабатываемым протоколом FIX (Financial Information eXchange), который используется для обработки данных при передаче между брокером и биржей, нужен ещё 1 инструмент для передачи и хранения данных. \
На очередном собрании:

*-- Итак, господа, прошу внимания, нашей группе специалистов, которая уже зарекомендовала себя по многим успешным проектам, выдана от правительства задача разработать абсолютно новый тип данных, кодовое название - Decimal. Его задача заключается в том, чтобы позволить на несколько десятилетий на порядки уменьшить погрешность, а в некоторых случаях и убрать ее полностью в финансовых мировых операциях. Нужно описать все необходимые логические и арифметические операции, которые позволили бы быстро и удобно производить нужные вычисления.*

*- Надо же, неплохой такой у нас заказ появился, и сразу от такого заказчика! Мы должны сохранить этого клиента, это сулит нам в дальнейшем большие контракты, если мы справимся!*

*-- Да, вы правы, поэтому сразу же надо понять, какие функции нам надо реализовывать... Предложения?*

*-- Сумма и разность....*

*-- Умножение и деление...*

*-- Согласен, но нужно ещё!*

*- Взятие остатка, операции сравнения и конвертации!*

*-- Математические округления во все стороны!*

*-- Да, думаю список уже вполне подходящий, за работу! На все у нас пару дней, не больше, не подведите!*

## Introduction

В этом проекте Вам предстоит реализовать библиотеку s21_decimal.h на языке программирования Си. Эта библиотека должна добавить возможность работы с типом "decimal", который отсутствует в стандарте языка. Тем не менее, этот тип критически важен для, например, финансовых расчетов, где недопустимы погрешности вычислений, свойственные типам с плавающей точкой. В рамках этого проекта предполагается знакомство с задачами обработки финансовой информации, погружение в вопросы внутреннего представления различных типов данных и закрепление структурного подхода.  


## Chapter II

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
| Сложение | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Вычитание | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Умножение | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Деление | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

Функции возвращают код ошибки:
- 0 - OK  
- 1 - число слишком велико или равно бесконечности
- 2 - число слишком мало или равно отрицательной бесконечности
- 3 - деление на 0

*Уточнение про числа, не вмещающиеся в мантиссу:*
- *При получении чисел, не вмещающихся в мантиссу при арифметических операциях, использовать банковское округление (например, 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)*


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

*Уточнение про преобразование числа типа float:*
- *Если числа слишком малы (0 < |x| < 1e-28), вернуть ошибку и значение, равное 0*
- *Если числа слишком велики (|x| > 79,228,162,514,264,337,593,543,950,335) или равны бесконечности, вернуть ошибку*
- *При обработке числа с типом float преобразовывать все содержащиеся в нём значимые десятичные цифры. Если таких цифр больше 7, то значение числа округляется к ближайшему, у которого не больше 7 значимых цифр.*

*Уточнение про преобразование из числа типа decimal в тип int:*
- *Если в числе типа decimal есть дробная часть, то её следует отбросить (например, 0.9 преобразуется 0)*


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
