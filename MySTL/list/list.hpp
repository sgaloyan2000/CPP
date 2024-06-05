#ifndef list_hpp
#define list_hpp

#include <stdio.h>
template<typename T>
class list{
public:
    struct Node {
        Node* ptr_next;
        Node* ptr_prev;
        T obj;
        Node();
        Node(const T&, Node*, Node*);
        Node* next();
        Node* prev();
    };
    list();
    void push_front(const T&);
    void display() const;
    void pop_front();
    void insert(const T&, const int&);
    void reverse();
    void push_back(const T&);
    bool empty();
    ~list();
private:
    Node* head;
    Node* tail;
};
#include "list.tpp"
#endif /* list_hpp */
