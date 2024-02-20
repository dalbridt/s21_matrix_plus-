#include "s21_matrix_oop.h"
#include <iostream>


S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols): rows_(rows), cols_(cols){
  // add exeption cols/ rows should be greater than 0; 
this->rows_ = rows;
this->cols_ = cols; 
matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = 0;
      }
    }

}

S21Matrix::~S21Matrix() {
    if (matrix_ != nullptr) {
      for (int i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
      }
      delete[] matrix_;
    }
  }
