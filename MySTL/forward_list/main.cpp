#include <iostream>
#include "forward_list.hpp"
int main() {
    forward_list<int> fl;
    std::cout<<fl.empty()<<std::endl;
    fl.push_front(3);
    fl.push_front(33);
    fl.push_front(123);
    fl.push_back(123412351);
    fl.display();
    std::cout<<std::endl;
    fl.pop_front();
    fl.pop_front();
    fl.insert(4022, 2);
    fl.display();
    std::cout<<std::endl;
    std::cout<<fl.has_cycle()<<std::endl;
    fl.make_cycle();
//    fl.display();
    std::cout<<fl.has_cycle()<<std::endl;
    
    return 0;
}
