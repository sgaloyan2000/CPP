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
    class input_iterator{
        Node* iter;
    public:
        input_iterator(Node*);
        T& operator *() const;
        T* operator ->() const;
        input_iterator& operator ++();
        input_iterator operator ++(int);
        bool operator == (const input_iterator&)const;
        bool operator != (const input_iterator&)const;
    };
    forward_list();
    input_iterator begin();
    input_iterator end();
    void push_front(const T&);
    void display() const;
    void pop_front();
    void insert(const T&, const int&);
    void reverse();
    T get_n_element_from_back(const int&);
    void push_back(const T&);
    void make_cycle();
    bool has_cycle();
    bool empty();
    ~forward_list();
private:
    Node* head;
};
#include "forward_list.tpp"
#endif /* forward_list_hpp */
