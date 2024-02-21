#include "s21_matrix_oop.h"
#include <exception>
#include <iostream>
#include <string>
using namespace std;

int main() {

  try {
    S21Matrix matrix(3, 3);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrix.GetMatrixElement(i, j) = 5; 
      }
    }
    S21Matrix second; 
    second = matrix; 
    matrix += second; 

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
       cout << matrix.GetMatrixElement(i, j) <<" " ;
      }
       cout << endl; 
    }
  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
