#include <iostream>
#include <cstdlib>
#include <ctime>


class Matrix{
    int** matrix;
    int row;
    int column;
public:
    Matrix(){
        matrix = nullptr;
    }
    Matrix(int rows, int columns){
        row = rows;
        column = columns;
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i)
            matrix[i] = new int[columns];
        srand(time(0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) 
                matrix[i][j] = rand() % 100;
        }
    }
    
    Matrix (const Matrix& obj){
        row = obj.row;
        column = obj.column;
        matrix = new int*[row];
        for (int i = 0; i < row; ++i)
            matrix[i] = new int[column];
        for (int i=0; i<row; ++i)
            for(int j=0; j<column; ++j)
                matrix[i][j] = obj.matrix[i][j];
    }
    Matrix& operator = (const Matrix& obj){
        for (int i = 0; i < row; ++i) 
                delete[] matrix[i];
        delete[] matrix;
        row = obj.row;
        column = obj.column;
        matrix = new int*[row];
        for (int i = 0; i < row; ++i)
            matrix[i] = new int[column];
        for (int i=0; i<row; ++i)
            for(int j=0; j<column; ++j)
                matrix[i][j] = obj.matrix[i][j];
        return *this;
    }
    Matrix operator+(const Matrix& obj){
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
    // postfix operator ++ (+=3)
    Matrix operator ++ (int) {
        Matrix temp = *this;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) 
                matrix[i][j] += 3;
        }
        return temp;
    }
    // prefix operator ++ (+=3)
    Matrix& operator ++ () {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) 
                matrix[i][j] += 3;
        }
        return *this;
    }
    void operator () (){
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
    
    void rotate() {
    int** rotate_matrix = new int*[column];
        for (int i = 0; i < column; ++i)
            rotate_matrix[i] = new int[row]; 
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
    
    ~Matrix(){
            for (int i = 0; i < row; ++i) 
                delete[] matrix[i];
        
        delete[] matrix;
    }
};



int main() {
    int row, column;
    std::cout << "Input the count of rows: ";
    std::cin >> row;
    std::cout << "Input the count of columns: ";
    std::cin >> column;
    Matrix matrix1(row,column);
    matrix1();
    // Matrix matrix2(matrix1);
    // matrix2();
    // Matrix matrix3;
    // matrix3 = matrix1; 
    // matrix3();
    // Matrix matrix4 = matrix1 + matrix2;
    // matrix4();
    (++matrix1)();
    (matrix1++)();
    matrix1();


    
    return 0;
}
