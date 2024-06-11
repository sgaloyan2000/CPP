#include <iostream>
#include <vector>
#include <cmath>
//51: Գրել ֆունկցիա որը օգտագործելով iterator-ներ կջնջի vector-ի միջի պարզ թվերը.

bool is_prime(int num){
    for (int i=2; i<=sqrt(num); ++i)
        if(num % i == 0)
            return false;
    return true;
}
void printer(const std::vector<int>& vec){
    for(auto i = vec.begin(); i != vec.end();++i){
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}
void eraser(std::vector<int>& vec){
    for(auto i = vec.begin(); i != vec.end();++i){
        if(is_prime(*i)){
            i = vec.erase(i);
            i--;
        }
    }
}
int main() {
    std::vector<int> vec = {4,5,1,62,17,5,8};
    printer(vec);
    eraser(vec);
    printer(vec);
    return 0;
}
