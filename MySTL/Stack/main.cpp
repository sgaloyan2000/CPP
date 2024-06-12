#include <iostream>
#include "stack.hpp"
int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(5);
    s.display();
    std::cout<<s.top()<<std::endl;
    s.pop();
    std::cout<<s.top()<<std::endl;

    return 0;
}
