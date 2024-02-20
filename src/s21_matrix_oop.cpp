#include "s21_matrix_oop.h"
#include <iostream>

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  // add exeption cols/ rows should be greater than 0;
  this->rows_ = rows;
  this->cols_ = cols;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 0;
    }
  }
 std::cout << "constructor called" << std::endl ;
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double *[this->rows_];
  for (int i = 0; i < this->rows_; ++i) {
    this->matrix_[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j]; 
    }
  }
 std::cout << "copy constructor called" << std::endl ;
}

S21Matrix::S21Matrix(S21Matrix&& other):rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_){
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  std::cout << "move constructor called" << std::endl ;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  } else{
    std::cout << "i found nullptr matrix" << std::endl ;
  }
  std::cout << "destructor called" << std::endl ;
}
