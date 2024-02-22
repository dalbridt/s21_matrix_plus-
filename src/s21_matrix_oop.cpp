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

S21Matrix::S21Matrix(S21Matrix &&other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
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
  if (!this->isValid() || !other.isValid()) {
    throw std::logic_error("invalid matrix");
  }
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
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!this->isValid() || !other.isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) += other.matrix_[i][j];
    }
  }
}
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!this->isValid() || !other.isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}
void S21Matrix::MulNumber(const double num) {
  if (!this->isValid()) {
    throw std::logic_error("invalid matrix");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      this->matrix_[i][j] *= num;
    }
  }
}
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (!this->isValid() || !other.isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (this->cols_ != other.rows_) {
    throw std::logic_error("matrix A columns must be equal to matrix B rows");
  }
  S21Matrix res(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      res(i, j) = 0;
      for (int k = 0; k < other.rows_; k++) {
        res(i, j) += (this->matrix_[i][k] * other.matrix_[k][j]);
      }
    }
  }

  *this = std::move(res);
}
S21Matrix S21Matrix::Transpose() {
  if (!this->isValid()) {
    throw std::logic_error("invalid matrix");
  }
  S21Matrix transposed(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      transposed(j, i) = matrix_[i][j];
    }
  }
  return transposed;
}

double S21Matrix::Determinant() {
  if (!this->isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (rows_ != cols_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }
  double result;
  switch (rows_) {
  case 1:
    result = matrix_[0][0];
    break;
  case 2:
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    break;
  default:
    result = 0;
    int sign = 1;
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = this->GetMinor(0, i);
      double determ_min = minor.Determinant();
      result += sign * matrix_[0][i] * determ_min;
      sign = -sign;
    }
    break;
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (!this->isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (rows_ != cols_ && (rows_ < 2 && cols_ < 2)) {
    throw std::logic_error(
        "Matrix dimensions must be equal and must be greater than 1");
  }
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = this->GetMinor(i, j);
      double calc = minor.Determinant();
      if ((i + j) % 2 != 0) {
        calc *= -1;
      }
      result(i, j) = calc;
    }
  }
  return result;
}
S21Matrix S21Matrix::InverseMatrix() {
  if (!this->isValid()) {
    throw std::logic_error("invalid matrix");
  }
  if (rows_ != cols_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }
  double determinant = Determinant();
  if (determinant == 0) {
    throw std::logic_error("Determinant must be non-zero");
  }

  S21Matrix temp_calc = CalcComplements();
  S21Matrix result = temp_calc.Transpose();
  result *= (1 / determinant);
  return result;
}

double &S21Matrix::GetMatrixElement(int row, int col) {
  if ((row < 0 || row > rows_ - 1) || (col < 0 || col > cols_ - 1)) {
    throw std::logic_error(
        " invalid parameters are passed in GetMatrixElement");
  }
  return matrix_[row][col];
}

S21Matrix S21Matrix::GetMinor(const int row_s, const int col_s) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int m_r = 0;
  for (int i = 0; i < rows_; i++) {
    int m_col = 0;
    if (i != row_s) {
      for (int j = 0; j < cols_; j++) {
        if (j != col_s) {
          minor(m_r, m_col) = matrix_[i][j];
          m_col++;
        }
      }
      m_r++;
    }
  }

  return minor;
}

bool S21Matrix::isValid() const {
  return matrix_ != nullptr && cols_ > 0 && rows_ > 0;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  if (this->cols_ != other.cols_ || this->rows_ != other.rows_) {
    throw std::logic_error("Matrix dimensions must be equal");
  }
  S21Matrix result(*this);
  result.SumMatrix(other);

  return result;
}
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);

  return result;
}
S21Matrix S21Matrix::operator*(double number) {
  S21Matrix result(*this);
  result.MulNumber(number);

  return result;
}
bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this->matrix_ != nullptr) {
    delete[] this->matrix_;
  }
  S21Matrix copy{other};
  *this = std::move(copy);
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}
S21Matrix &S21Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  return GetMatrixElement(row, col);
}
