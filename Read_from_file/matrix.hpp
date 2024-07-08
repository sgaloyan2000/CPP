#ifndef matrix_hpp
#define matrix_hpp
template <class T>
class Matrix{
    T** matrix;
    int row;
    int column;
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix (const Matrix& obj);
    Matrix (Matrix&& obj);
    Matrix& operator = (const Matrix& obj);
    Matrix operator * (const Matrix& obj);
    Matrix operator+(const Matrix& obj);
    void operator () ();
    T* operator [](const int& index);
    void rotate();
    int get_row() const;
    int get_column() const;
    T at(const int&, const int&);
    ~Matrix();
};

#include "matrix.tpp"
#endif /* matrix_hpp */
