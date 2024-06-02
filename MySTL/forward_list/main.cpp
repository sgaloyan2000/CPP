#include <iostream>
#include "forward_list.hpp"
int main() {
    forward_list<int> fl;
    fl.push_front(3);
    fl.push_front(33);
    fl.push_front(123);
    fl.push_front(43);
    fl.push_front(32);
    fl.push_front(31);
    fl.display();
    std::cout<<std::endl;
    fl.pop_front();
    fl.pop_front();
    fl.insert(4022, 2);
    fl.display();
    std::cout<<std::endl;
    std::cout<<fl.empty();
    std::cout<<std::endl;
    
    return 0;
}
