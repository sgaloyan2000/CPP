#include <iostream>
#include "my_vector.hpp"

int main ()
{
    myvector<int> vec({1,2,5,6,2});
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.push_back(4);
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.insert(5, 2);
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.push_front(900);
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.pop_back();
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    vec.pop_front();
    vec.print();
    std::cout<<"size = "<<vec.get_size()<<std::endl;
    std::cout<<"capacity = "<<vec.get_capacity()<<std::endl;
    std::cout<<"is empety? "<<vec.empty()<<std::endl;
    return 0;
}
