#include "list.hpp"
#include <iostream>

int main() {
    list<int> l;
    //std::cout<<l.empty()<<std::endl;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(11);
    l.push_back(22);
    l.push_back(33);
    l.display();
    l.pop_front();
    l.pop_front();
    l.display();
    l.insert(2, 2);
    l.display();
    l.reverse();
    l.display();
    return 0;
}
