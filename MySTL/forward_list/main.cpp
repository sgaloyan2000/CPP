#include <iostream>
#include "forward_list.hpp"
int main() {
    forward_list<int> fl;
    //std::cout<<fl.empty()<<std::endl;
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);
    fl.push_back(4);
    //fl.display();
    //std::cout<<std::endl;
    //fl.pop_front();
    //fl.pop_front();
    fl.insert(5, 4);
    fl.display();
    std::cout<<std::endl;
    //std::cout<<fl.has_cycle()<<std::endl;
    //fl.make_cycle();
    //fl.display();
    //std::cout<<fl.has_cycle()<<std::endl;
    //fl.reverse();
    std::cout<<fl.get_n_element_from_back(1)<<std::endl;
    std::cout<<std::endl;
    fl.display();
    return 0;
}
