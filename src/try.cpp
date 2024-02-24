#include <exception>
#include <iostream>
#include <string>

#include "s21_matrix_oop.h"
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
    auto test1 = S21Matrix(1, 1);
    test1.setCols(5);
    test1.setRows(5);
    print_matrix(test1);

  } catch (exception &er) {
    cout << er.what() << endl;
  }
  return 0;
}
