CC = g++ # gcc -lstdc++
SRC = s21_matrix_oop.cpp
OBJ_OOP_O = s21_matrix_oop.o
OBJ_TEST_O = s21_matrix_test.o
ARCHIVER_OOP = s21_matrix_oop.a
ARCHIVER_TEST = s21_matrix_test.a
FLAGS= -Wall -Werror -Wextra -std=c++17
TESTFLAGS=-lgtest

# OS choice 
all: clean fromat test_sequence 
test_sequence: test call_test # report genhtml 
test: 
s21_matrix_oop.a:
	$(CC) -c $(FLAGS) $(SRC) -o $(OBJ_OOP_O)
#ar -rcs $(ARCHIVER_OOP) $(OBJ_OOP_O)
try: clean
	$(CC) -c $(FLAGS) try.cpp -o try.o
	$(CC) -c $(FLAGS) $(SRC) -o $(OBJ_OOP_O)
	ar -rcs $(ARCHIVER_OOP) try.o $(OBJ_OOP_O)
	$(CC) -o try.out try.o $(OBJ_OOP_O)
	./try.out
clean: 
	rm -rf *.out *.o *.gcno *.info s21_matrix_oop.a *.gcda *.a *.o
	rm -rf report
leaks: 
	leaks -atExit -- ./try.out

