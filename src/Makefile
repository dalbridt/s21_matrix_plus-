CC = g++ 
SRC = s21_matrix_oop.cpp
OBJ = s21_matrix_oop.o
OBJ_TEST = s21_matrix_test.o
LIB = s21_matrix_oop.a
FLAGS= -Wall -Werror -Wextra -std=c++17
TESTFLAGS= -pthread -lgtest -lgmock
HECK_FLAG = -lstdc++
LCOVFLAGS = --ignore-errors inconsistent --ignore-errors mismatch

# OS choice 
all: clean fromat test_sequence 
test_sequence: test call_test # report genhtml 
s21_matrix_oop.a:
	$(CC) -c $(FLAGS) $(SRC) -o $(OBJ)
	ar -rcs $(LIB) $(OBJ)
	ranlib $(LIB)
	rm -rf *.o
test: clean s21_matrix_oop.a
	$(CC) $(FLAGS) -c test.cpp -o test.o
	$(CC) $(FLAGS) $(CHECK_FLAG) test.o $(LIB) $(TESTFLAGS) -o test
	rm -rf *.o
	./test
gcov_report: add_coverage_flag test
	./test
	lcov -t "test" -o test.info -c -d ./  --no-external $(LCOVFLAGS)
	genhtml -o report test.info $(LCOVFLAGS)
	open report/index.html
add_coverage_flag:
	$(eval FLAGS += --coverage)

try: clean
	$(CC) -c $(FLAGS) try.cpp -o try.o
	$(CC) -c $(FLAGS) $(SRC) -o $(OBJ)
	ar -rcs $(LIB) try.o $(OBJ)
	$(CC) -o try.out try.o $(OBJ)
	./try.out
clean: 
	rm -rf *.out *.o *.gcno *.info s21_matrix_oop.a *.gcda *.a *.o
	rm -rf report 
	rm -rf test
leaks: 
	leaks -atExit -- ./try.out

