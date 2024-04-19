#include <iostream>
#include <cstdlib>
#include <ctime>



class Matrix{
    int** matrix;
    int row;
    int column;
public:
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
    
    void printer() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
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
    Matrix matrix(row,column);
    matrix.printer();
    matrix.rotate();
    matrix.printer();
  


    return 0;
}