#include <iostream>

class array{
    int* ptr = nullptr;
    int size;
public:
    array(){
        this->size = 0;
    }
    array(int size)
    {
        this->size = size;
        ptr = new int(size);
    }
    array (const array& obj){
        this->size = obj.size;
        ptr = new int(size);
        for(int i=0; i<size; i++){
            ptr[i] = obj.ptr[i];
        }
    }
    array& operator = (const array& obj){
        if(this == &obj){
            return *this;
        }
        else{
            this->size = obj.size;
            for(int i=0; i<size; i++){
                this->ptr[i] = obj.ptr[i];
            }
            return *this;
        }
    }
    int& operator [] (const int& index){
        return *(ptr+index);
    }
    friend std::ostream& operator << (std::ostream& os,const array& obj){
        for (int i=0; i<obj.size; i++){
            os<<obj.ptr[i]<<' ';
        }
        return os;
    }
    ~array(){
        delete ptr;
    }
};


int main(){
    array b(5);
    for (int i=0; i<5; i++){
        b[i]=i;
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<b;
    return 0;
}
