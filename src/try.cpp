#include "s21_matrix_oop.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

void print_matrix(S21Matrix matrix) {
  for (int i = 0; i < matrix.getRows(); i++) {
    for (int j = 0; j < matrix.getCols(); j++) {
      cout << matrix(i, j) << "  ";
    }
    cout << endl;
  }
}

int main() {
  try {
    auto test1 = S21Matrix(2, 3);
    test1(0, 0) = 1;
    test1(0, 1) = 2;
    test1(0, 2) = 3;
    test1(1, 0) = 0;
    test1(1, 1) = 4;
    test1(1, 2) = 2;
    test1.CalcComplements();
  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
