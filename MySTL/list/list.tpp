#include "list.hpp"
#include <iostream>
template<typename T>
list<T>::Node::Node() : ptr_next(nullptr),ptr_prev(nullptr) {}
    
template<typename T>
list<T>::Node::Node(const T& t, Node* pn,Node* pp) : obj(t), ptr_next(pn),ptr_prev(pp) {}

template<typename T>
typename list<T>::Node* list<T>::Node::next() { return ptr_next;} //  typename?

template<typename T>
typename list<T>::Node* list<T>::Node::prev() { return ptr_prev;}

template<typename T>
list<T>::list():head(nullptr),tail(nullptr){}

template<typename T>
void list<T>::push_front(const T& obj) {
    Node* new_node = new Node(obj, head, nullptr);
    if (head) {
        head->ptr_prev = new_node;
    }
    head = new_node;
    if (!tail) {
        tail = head;
    }
}

template<typename T>
void list<T>::push_back(const T& obj){
    Node* new_node = new Node(obj, nullptr, tail);
    if (tail) {
        tail->ptr_next = new_node;
    }
    tail = new_node;
    if (!head) {
        head = tail;
    }
}
template<typename T>
void list<T>::display() const {
    Node* reader = head;
    while (reader) {
        std::cout << reader->obj << std::endl;
        reader = reader->next();
    }
    std::cout<<std::endl;
}
template<typename T>
void list<T>:: pop_front(){
    if (head) {
        Node* temp = head;
        head = head->next();
        if(head){
            head->ptr_prev = nullptr;
        }
        else{
            tail = nullptr;
        }
        delete temp;
    }
}
template<typename T>
void list<T>::insert(const T& obj, const int& index){
    if (index == 0){
        push_front(obj);
        return;
    }
    int counter = 0;
    Node* temp = head;
    
    while (temp && counter < index-1) {
        temp = temp->next();
        counter++;
    }
    if(temp == nullptr){
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    Node* new_node = new Node(obj, temp->ptr_next, temp);
    if (temp->ptr_next) {
        temp->ptr_next->ptr_prev = new_node;
    }
    temp->ptr_next = new_node;

    if (new_node->ptr_next == nullptr) {
        tail = new_node;
    }
}
template<typename T>
bool list<T>::empty(){
    return head == nullptr;
}
template<typename T>
void list<T>::reverse() {
    if (!head) {
        return;
    }

    Node* current = head;
    Node* temp = nullptr;

    while (current) {
        temp = current->prev();
        current->ptr_prev = current->next();
        current->ptr_next = temp;
        current = current->prev();
    }
    if(temp){
        temp = head;
        head = tail;
        tail = temp;
    }
}

template<typename T>
list<T>::~list() {
    while (head) {
        Node* temp = head;
        head = head->next();
        delete temp;
    }
}
