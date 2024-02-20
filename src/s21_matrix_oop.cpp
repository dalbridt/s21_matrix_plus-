#include "s21_matrix_oop.h"
#include <iostream>
#include <cmath>

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::length_error("Matrix size must be greater than 0");
  } else {
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] = 0;
      }
    }
  }
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
  // std::cout << "copy constructor called" << std::endl ;
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  // std::cout << "move constructor called" << std::endl ;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  // std::cout << "destructor called" << std::endl ;
}

int S21Matrix::get_cols() { return cols_; }
int S21Matrix::get_rows() { return rows_; }

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 1) {
    throw std::length_error("matrix rows should be > 1");
  }
  // if (new_rows != rows_) {
  //   S21Matrix tmp; // {new_rows, cols_};
  //   int min = std::min(rows_, new_rows);
  //   for (int i = 0; i < min; ++i) {
  //     for (int j = 0; j < cols_; ++j) {
  //       tmp(i, j) = (*this)(i, j);
  //     }
  //   }
  //   *this = std::move(tmp);
  // }
}
void S21Matrix::set_cols(int new_cols) {
  //
}

 bool S21Matrix::EqMatrix(const S21Matrix &other){
  bool flag = true; 
  // нужно validate matrix 
  if(this->rows_ != other.rows_ || this->cols_ !=other.cols_){
    flag = false; 
  } 
  if(flag){
    for (int i = 0; i < rows_ && flag; i++) {
      for (int j = 0; j < cols_; j++) {
        if (EPS < std::fabs(this->matrix_[i][j] - other.matrix_[i][j])) {
          flag=false; 
          break;
        }
      }
    }
  }
  return flag; 
 }
  // void S21Matrix::SumMatrix(const S21Matrix &other){}
  // void S21Matrix::SubMatrix(const S21Matrix &other){}
  // void S21Matrix::MulNumber(const double num){}
  // void S21Matrix::MulMatrix(const S21Matrix &other){}
  // S21Matrix S21Matrix::Transpose(){}
  // S21Matrix S21Matrix::CalcComplements(){}
  // double S21Matrix::Determinant(){}
  // S21Matrix S21Matrix::InverseMatrix(){}

