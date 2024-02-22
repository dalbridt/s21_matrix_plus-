#include "s21_matrix_oop.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

void print_matrix(S21Matrix matrix) {
  for (int i = 0; i < matrix.get_rows(); i++) {
    for (int j = 0; j < matrix.get_cols(); j++) {
      cout << matrix(i, j) << " !! ";
    }
    cout << endl;
  }
}

int main() {
  try {
    S21Matrix matrix(3, 3);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrix.GetMatrixElement(i, j) = 7;
      }
    }
    // S21Matrix second(3, 3);
    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     second.GetMatrixElement(i, j) = 2;
    //   }
    // }
    // S21Matrix res = matrix* 5;
    print_matrix(matrix);

    cout << endl;
    matrix.set_rows(5);
    cout << matrix.get_rows() << endl;

    print_matrix(matrix);
    cout << endl;
    matrix.set_cols(5);
    print_matrix(matrix);
  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
