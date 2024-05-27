#include <iostream>
#include "my_vector.hpp"

int main ()
{
    myvector<int> vec(10);
    for (int i=0; i<10; i++){
        vec[i] =  i;
        std::cout<<i<<" = "<<vec[i]<<std::endl;
    }
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.push_back(4);
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    std::cout<<"is empety? "<<vec.empty()<<std::endl;
    return 0;
}
