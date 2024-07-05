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
    std::cout<<"is empty? "<<vec.empty()<<std::endl;
    std::cout<<vec.at(0)<<std::endl;
    try{
        std::cout<<vec.at(10)<<std::endl;
    }
    catch(std::out_of_range& e){
        std::cerr<<e.what()<<std::endl;
    }
    catch(MyException& e){
        std::cerr<<e.what()<<std::endl;
    }
    
    return 0;
}
