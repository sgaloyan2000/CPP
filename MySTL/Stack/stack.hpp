#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include"/Users/Serzh/Documents/xcode/homework/homework/my_stl/forward_list/forward_list.hpp"
template <typename T>
class stack{
    forward_list<T> m_stack;
public:
    T& top();
    bool empty();
    int size();
    void push(const T&);
    void pop();
    void display()const;
};
#include "stack.tpp"
#endif /* stack_hpp */
