#include "stack.hpp"

template <typename T>
void stack<T>::push(const T& obj){
    m_stack.push_front(obj);
}
template <typename T>
void stack<T>::pop(){
    m_stack.pop_front();
}
template <typename T>
T& stack<T>::top(){
    return *m_stack.begin();
}
template <typename T>
bool stack<T>::empty(){
    return m_stack.empty();
}
template <typename T>
int stack<T>::size(){
    int counter = 0;
    for(auto i = m_stack.begin(); i != m_stack.end();++i){
        counter++;
    }
    return counter;
}
template <typename T>
void stack<T>::display()const{
    m_stack.display();
}
