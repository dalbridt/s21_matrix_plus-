#include "s21_matrix_oop.h"
#include <cmath>
#include <iostream>

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
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  std::cout << "move constructor called" << std::endl; 
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

int S21Matrix::get_cols() { return cols_; }
int S21Matrix::get_rows() { return rows_; }

void S21Matrix::set_rows(int new_rows) {
  if (new_rows < 1) {
    throw std::length_error("matrix rows should be > 1");
  }
  if (new_rows != rows_) {
    S21Matrix tmp(new_rows, cols_);
    int min = std::min(rows_, new_rows);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < cols_; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
   *this = std::move(tmp);
  }
}
void S21Matrix::set_cols(int new_cols) {
   if (new_cols < 1) {
    throw std::length_error("matrix columns should be > 1");
  }
  S21Matrix tmp(rows_, new_cols);
  int min = std::min(cols_, new_cols); 
   for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < min; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
  }
  *this = std::move(tmp);
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool flag = true;
  // нужно validate matrix
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    flag = false;
  }
  if (flag) {
    for (int i = 0; i < rows_ && flag; i++) {
      for (int j = 0; j < cols_; j++) {
        if (EPS < std::fabs(this->matrix_[i][j] - other.matrix_[i][j])) {
          flag = false;
          break;
        }
      }
    }
  }
  return flag;
}
void S21Matrix::SumMatrix(const S21Matrix &other){
  if(this->rows_ != other.rows_ || this->cols_ != other.cols_){
    throw std::logic_error("Matrix dimensions must be equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i,j) += other.matrix_[i][j]; 
    }
  }
  std::cout << std::endl;
}
void S21Matrix::SubMatrix(const S21Matrix &other){
    if(this->rows_ != other.rows_ || this->cols_ != other.cols_){
    throw std::logic_error("Matrix dimensions must be equal");
  }
    for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}
void S21Matrix::MulNumber(const double num){
  //validate matrix 
   for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] *= num;
    }
   }
}
// void S21Matrix::MulMatrix(const S21Matrix &other){
//   // WRITEME 
// }
// S21Matrix S21Matrix::Transpose(){}
// S21Matrix S21Matrix::CalcComplements(){}
// double S21Matrix::Determinant(){}
// S21Matrix S21Matrix::InverseMatrix(){}

double &S21Matrix::GetMatrixElement(int row, int col) {
  return matrix_[row][col];
}

// S21Matrix S21Matrix::GetMinor(const int row_s, const int col_s){}
// bool isValid(){}

S21Matrix S21Matrix::operator+(const S21Matrix& other){
if( this->cols_ != other.cols_ || this->rows_ != other.rows_){
 throw std::logic_error("Matrix dimensions must be equal");
}
S21Matrix result(*this); 
result.SumMatrix(other);

return result; 
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
S21Matrix result(*this); 
result.SubMatrix(other);

return result; 
}
S21Matrix S21Matrix::operator*(double number){
S21Matrix result(*this); 
result.MulNumber(number);

return result; 
}
bool S21Matrix::operator==(const S21Matrix &other) {
  return EqMatrix(other);
}
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this->matrix_ != nullptr) {
    delete[] this->matrix_;
  }
  // можно бы было вызвать конструктор копирования, но я хз как
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double *[this->rows_];
  for (int i = 0; i < this->rows_; ++i) {
    this->matrix_[i] = new double[this->cols_];
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other){
  SumMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other){
  SubMatrix(other);
  return *this;
}
S21Matrix& S21Matrix::operator*=(double number){
  MulNumber(number); 
  return *this; 
}
// S21Matrix& operator*=(const S21Matrix& other){}

double& S21Matrix::operator()(int row, int col) {
  return GetMatrixElement(row, col); 
}
