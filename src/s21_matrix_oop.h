#ifndef S21MATRIX
#define S21MATRIX
// #include <iostream>

class S21Matrix {
private:
  int rows_, cols_;
  double **matrix_;

public:
  S21Matrix(); // Default constructor
  S21Matrix(int rows, int cols); // constructor with attributes 
  S21Matrix(const S21Matrix& other); // copy constructor 
  S21Matrix(S21Matrix&& other); // move constructor 
  ~S21Matrix(); // Destructor

  // accessors and mutators
  int get_cols();
  int get_rows();
  void set_rows(int new_rows);
  void set_cols(int new_cols);

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // overload operators 
};

#endif