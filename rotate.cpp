#include <iostream>
#include <cstdlib>
#include <ctime>


void matrix_maker(int* matrix, int m, int n)
{
    srand(time(0));
    for(int i=0; i<m*n; i++){
            matrix[i] = rand()%100;
        }
    
}

void printer(int* matrix, int m, int n)
{
    for(int i=0; i<m; i++){
        for(int j = i * n; j < i * n + n; j++){
            std::cout<<matrix[j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void rotate(int* matrix, int m, int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j < m; j++){
            std::cout<<matrix[j*n+i]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
int main() 
{
    int row, column;
    std::cout<<"Input the count of rows: count = "<<std::endl;
    std::cin>>row;
    std::cout<<"Input the count of columns: count = "<<std::endl;
    std::cin>>column;
    
    int* matrix = (int*) malloc(row*column*sizeof(int));
    
        
    matrix_maker(matrix,row, column);
    printer(matrix,row, column);
    rotate(matrix,row,column);
    free(matrix);
    
  return 0;
}