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
    S21Matrix matrix(3, 2);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
        matrix.GetMatrixElement(i, j) = i+j;
      }
    }
    print_matrix(matrix);
    cout << endl;
    S21Matrix second = matrix.Transpose(); 
    // S21Matrix second(2, 3);
    // for (int i = 0; i < 2; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     second.GetMatrixElement(i, j) = i - j;
    //   }
    // }
   // print_matrix(second);
    cout << endl;
    // matrix *= second; 
    print_matrix(second);

  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
