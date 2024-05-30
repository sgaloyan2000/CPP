#include <iostream>
void print(){
    std::cout<<std::endl;
}
template <typename T,typename... args>
void print(T input, args... a){
    std::cout<<input<<" ";
    print(a...);
}
//???????????
// Variadic template function using fold expression
// template<typename... args>
// auto sum(args... a) {
//     return (a + ...); // Fold expression
// }

int main()
{
    print(1.3,3,4,5,6,'s',"Hello",true);
    //std::cout << sum(1, 2, 3, 4, 5) << std::endl; 

    return 0;
}
