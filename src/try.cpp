#include "s21_matrix_oop.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {
  try {
    S21Matrix matrix(3, 5);

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
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << matrix(i, j) << " !! ";
      }
      cout << endl;
    }
    
      cout << endl;
    matrix.set_rows(5);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << matrix(i, j) << " !! ";
      }
      cout << endl;
    }
      cout << endl;
    matrix.set_cols(5);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << matrix(i, j) << " !! ";
      }
      cout << endl;
    }
  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
