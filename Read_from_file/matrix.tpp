#include "matrix.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>
Matrix<T>::Matrix(){
    matrix = nullptr;
}
template <class T>
Matrix<T>::Matrix(int rows, int columns){
    row = rows;
    column = columns;
    matrix = new T*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new T[columns];
    std::srand(std::time(0));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            matrix[i][j] = rand() % 10;
    }
}
    
template <class T>
Matrix<T>::Matrix (const Matrix& obj){
    row = obj.row;
    column = obj.column;
    matrix = new T*[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new T[column];
    for (int i=0; i<row; ++i)
        for(int j=0; j<column; ++j)
            matrix[i][j] = obj.matrix[i][j];
}
template <class T>
Matrix<T>::Matrix (Matrix&& obj){
    row = obj.row;
    column = obj.column;
    matrix = obj.matrix;
    obj.column = 0;
    obj.row = 0;
    obj.matrix = nullptr;
}

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix& obj){
    for (int i = 0; i < row; ++i)
            delete[] matrix[i];
    delete[] matrix;
    row = obj.row;
    column = obj.column;
    matrix = new T*[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new T[column];
    for (int i=0; i<row; ++i)
        for(int j=0; j<column; ++j)
            matrix[i][j] = obj.matrix[i][j];
    return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& obj){
    if (row != obj.row || column != obj.column) {
        std::cout << "Parameters of matrices you're trying to sum do not match" << std::endl;
        return Matrix(0, 0);
    } else {
        Matrix temp(row, column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
            }
        }
        return temp;
    }
}
    
template <class T>
void Matrix<T>::operator () (){
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
    
template <class T>
void Matrix<T>::rotate() {
T** rotate_matrix = new T*[column];
    for (int i = 0; i < column; ++i)
        rotate_matrix[i] = new T[row];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            rotate_matrix[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row / 2; j++) {
            std::swap(rotate_matrix[i][j], rotate_matrix[i][row - 1 - j]);
        }
    }
    matrix = rotate_matrix;
    std::swap(row,column);
}
    
template <class T>
Matrix<T>::~Matrix(){
        for (int i = 0; i < row; ++i)
            delete[] matrix[i];
    
    delete[] matrix;
}
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix& obj){
    if (column == obj.row) {
        Matrix<T> temp (row, obj.column);
        for(int i=0; i<row; i++){
            for(int j=0; j<obj.column; j++){
                temp.matrix[i][j] = 0;
                for(int z=0; z<column; z++)
                    temp.matrix[i][j] += matrix[i][z] * obj.matrix[z][j];
                }
        }
        return temp;
    } else {
        std::cout << "Parameters of matrices you're trying to sum do not match" << std::endl;
        return Matrix(0, 0);
    }
}
template<class T>
int Matrix<T>::get_row()const{
    return row;
}
template<class T>
int Matrix<T>::get_column()const{
    return column;
}
template<class T>
T* Matrix<T>::operator [] (const int& index)const {
    return matrix[index];
}
