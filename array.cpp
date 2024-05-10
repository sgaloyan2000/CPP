#include <iostream>

class array{
    int* ptr = nullptr;
    int size;
public:
    array(){}
    array(int size)
    {
        this->size = size;
        int ptr1[size];
        ptr = ptr1;
    }
    int& operator [] (const int& index){
        return *(ptr+index);
    }
    friend std::ostream& operator << (std::ostream& os,const array& obj);
};
std::ostream& operator << (std::ostream& os,const array& obj){
        for (int i=0; i<obj.size; i++){
            os<<obj.ptr[i]<<' ';
        }
        return os;
    }

int main(){
    array a;
    array b(5);
    for (int i=0; i<5; i++){
        b[i]=i;
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<b;
    return 0;
}
