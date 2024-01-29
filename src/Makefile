CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 #-Wpedantic #-ansi
ASAN=#-fsanitize=address -g
GCOV_FLAGS=--coverage
OS=$(shell uname -s)
USERNAME=$(shell whoami)
LIB_FILES=arithmetic/s21*.c comparison/s21*.c converters/s21*.c another/s21*.c s21*.c
TEST_FILES=unit_tests/*.c

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
	ADD_LIB=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	BREW=.
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open 
	ADD_LIB=-lm -lcheck -lpthread
	BREW:=${HOME}/homebrew 
endif

all: clean s21_decimal.a test gcov_report

clean:
	@rm -rf *.out *.o *.a
	@rm -rf *.gcno *.gcda *.info
	@rm -rf report/
	@rm -rf s21_decimal_test

test: clean s21_decimal.a
	@$(CC) -c $(CFLAGS) $(TEST_FILES) $(ADD_LIB)
	@$(CC) $(CFLAGS) s21_*.o s21_decimal.a -o s21_decimal_test $(ADD_LIB)
	./s21_decimal_test
	@rm -rf *.o *.a s21_decimal_test

s21_decimal.a: clean
	@$(CC) -c $(CFLAGS) $(LIB_FILES) $(ADD_LIB)
	@ar -rcs s21_decimal.a s21_*.o
	@rm -rf *.o

gcov_report: clean
	@$(CC) $(CFLAGS) $(ASAN) $(GCOV_FLAGS) $(LIB_FILES) $(TEST_FILES) -o gcov_test $(ADD_LIB)
	./gcov_test
	@lcov -c -d . -o gcov_test.info
	@rm -rf *.out *.o *.gcno *.gcda gcov_test
	@genhtml -o report gcov_test.info
	@chmod 777 report/*
	@$(OPEN_CMD) ./report/index.html
	@rm -rf report/ *.info

leaks: clean
	@$(CC) $(CFLAGS) $(ASAN) $(LIB_FILES) $(TEST_FILES) -o leaks_test $(ADD_LIB)
	$(LEAK_CHECK) ./leaks_test
	@rm -rf leaks_test

clang:
	@cp ../materials/linters/.clang-format .
	@clang-format -i *.c *.h unit_tests/*.h $(LIB_FILES) $(TEST_FILES) 
	@rm -rf .clang-format
	@clear
