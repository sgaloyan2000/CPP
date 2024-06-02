#ifndef forward_list_hpp
#define forward_list_hpp

#include <stdio.h>
template<typename T>
class forward_list{
public:
    struct Node {
        Node* ptr;
        T obj;
        Node();
        Node(const T&, Node*);
        Node* next();
    };
    forward_list();
    void push_front(const T&);
    void display() const;
    void pop_front();
    void insert(const T&, const int&);
    bool empty();
    ~forward_list();
private:
    Node* head;
};
#include "forward_list.tpp"
#endif /* forward_list_hpp */
