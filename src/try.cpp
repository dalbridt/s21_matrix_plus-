#include "s21_matrix_oop.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

void print_matrix(S21Matrix matrix) {
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      cout << matrix(i, j) << "  ";
    }
    cout << endl;
  }
}

int main() {
  try {
    S21Matrix matrix(3, 3);
    matrix(0, 0) = 2;
    matrix(0, 1) = 5;
    matrix(0, 2) = 7;
    matrix(1, 0) = 6;
    matrix(1, 1) = 3;
    matrix(1, 2) = 4;
    matrix(2, 0) = 5;
    matrix(2, 1) = -2;
    matrix(2, 2) = -3;

    S21Matrix second = matrix.InverseMatrix();
    print_matrix(matrix);
    cout << endl;
    print_matrix(second); 


  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
