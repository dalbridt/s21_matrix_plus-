#ifndef S21MATRIX
#define S21MATRIX

class S21Matrix {
private:
  int rows_, cols_;
  double **matrix_;
  const double EPS = 1e-7;

public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // accessors and mutators
  int getCols();
  int getRows();
  void setRows(int new_rows);
  void setCols(int new_cols);
  // core functions
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // helpers
  double &GetMatrixElement(int row, int col);
  S21Matrix GetMinor(const int row_s, const int col_s);
  bool isValid() const;

  // overloaded operators
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(double number);
  bool operator==(const S21Matrix &other) const;
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(double number);
  S21Matrix &operator*=(const S21Matrix &other);
  double &operator()(int row, int col);

};

#endif