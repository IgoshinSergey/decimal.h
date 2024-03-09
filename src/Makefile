CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV_FLAGS=--coverage
OS=$(shell uname -s)
LIB_FILES=arithmetic/s21*.c comparison/s21*.c converters/s21*.c another/s21*.c s21*.c
TEST_FILES=unit_tests/*.c

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
	ADD_LIB=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open 
	ADD_LIB=-lm -lcheck -lpthread
endif

all: s21_decimal.a test gcov_report clang clean

s21_decimal.a: clean
	@$(CC) -c $(CFLAGS) $(LIB_FILES) $(ADD_LIB)
	ar -rcs s21_decimal.a s21_*.o
	@rm -rf *.o

test: clean s21_decimal.a
	@$(CC) -c $(CFLAGS) $(TEST_FILES) $(ADD_LIB)
	@$(CC) $(CFLAGS) s21_*.o s21_decimal.a -o test $(ADD_LIB)
	./test
	@rm -rf *.o *.a test

gcov_report: clean
	@$(CC) $(CFLAGS) $(ASAN) $(GCOV_FLAGS) $(LIB_FILES) $(TEST_FILES) -o gcov_test $(ADD_LIB)
	./gcov_test
	@lcov -c -d . -o gcov_test.info
	@rm -rf *.out *.o *.gcno *.gcda gcov_test
	@genhtml -o report gcov_test.info
	@chmod 777 report/*
	@$(OPEN_CMD) ./report/index.html
	@rm -rf report/ *.info

clean:
	@rm -rf *.out *.o *.a
	@rm -rf *.gcno *.gcda *.info
	@rm -rf report/
	@rm -rf test gcov_test

leaks: clean
	@$(CC) $(CFLAGS) $(ASAN) $(LIB_FILES) $(TEST_FILES) -o leaks_test $(ADD_LIB)
	$(LEAK_CHECK) ./leaks_test
	@rm -rf leaks_test

clang:
	clang-format -i *.c *.h unit_tests/*.h $(LIB_FILES) $(TEST_FILES) 
