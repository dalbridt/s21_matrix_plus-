#ifndef S21MATRIX
#define S21MATRIX
// #include <iostream>

class S21Matrix {
private:
  int rows_, cols_;
  double **matrix_;
  const double EPS = 1e-7;

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

  // helpers 
  double& GetMatrixElement(int row, int col); // по ссылке, чтоб можно было поменять E.G.: matrix.GetMatrixElement(1, 2) = 5.0; 
  S21Matrix GetMinor(const int row_s, const int col_s); 

  // overload operators 

  
  // S21Matrix operator+(const S21Matrix& other) ;
  // S21Matrix operator-(const S21Matrix& other) const;
  // S21Matrix operator*(double number) const noexcept;
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other); 
  S21Matrix& operator+=(const S21Matrix& other);
  // S21Matrix& operator-=(const S21Matrix& other);
  // S21Matrix& operator*=(double number);
  // (int i, int j)
/*
  double& operator()(int row, int col) &;
  double& operator()(int row, int col) && = delete;
  const double& operator()(int row, int col) const&;
  const double& operator()(int row, int col) const&& = delete;
  friend S21Matrix operator*(double number, const S21Matrix& matrix);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);*/
};

#endif