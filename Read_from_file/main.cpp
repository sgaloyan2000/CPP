#include "matrix.hpp"
#include <fstream>

void generate_matrix_file(const std::string& filename,  Matrix<int>& data) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return;
    }
    outFile<<data.get_row()<<" "<<data.get_column()<<std::endl;
    
    for(int i = 0; i < data.get_row(); i++) {
        for(int j = 0; j < data.get_column(); j++){
            outFile << data[i][j]  << " ";
        }
        outFile<<std::endl;
    }

    outFile.close();

    if (outFile.fail()) {
        std::cerr << "Error: Could not properly close the file." << std::endl;
    } else {
        std::cout << "File has been generated successfully: " << filename << std::endl;
    }
}

Matrix<int> read_matrix_from_file(const std::string& filename1,const std::string& filename2) {
    std::ifstream inFile1(filename1);

    if (!inFile1) {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
        return Matrix<int>(); // Return an empty matrix
    }

    int rows, columns;
    inFile1 >> rows >> columns;

    Matrix<int> matrix1(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            inFile1 >> matrix1[i][j];
        }
    }

    inFile1.close();
    
    std::ifstream inFile2(filename2);

    if (!inFile2) {
        std::cerr << "Error: Unable to open the file for reading." << std::endl;
        return Matrix<int>(); // Return an empty matrix
    }

    inFile2 >> rows >> columns;

    Matrix<int> matrix2(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            inFile2 >> matrix2[i][j];
        }
    }

    inFile2.close();

    return matrix1*matrix2;
}


int main() {
    int row, column;
    std::cout << "Input the count of rows: ";
    std::cin >> row;
    std::cout << "Input the count of columns: ";
    std::cin >> column;
    Matrix<int> matrix1(row,column);
    matrix1();
    Matrix<int> matrix2(column, row);
    matrix2();
    std::cout<<matrix1[2][2]<<std::endl;
    std::cout<<matrix1.at(2,2)<<std::endl;
    try {
        std::cout<< matrix1.at(10, 1)<<std::endl;
    }
    catch(std::out_of_range &e){
        std::cerr<<e.what()<<std::endl;
    }
    
//    generate_matrix_file("matrix1.txt", matrix1);
//    generate_matrix_file("matrix2.txt", matrix2);
//    Matrix<int> matrix3(read_matrix_from_file("matrix1.txt", "matrix2.txt"));
//    matrix3();
//    generate_matrix_file("output_matrix.txt", matrix3);
    return 0;
}
