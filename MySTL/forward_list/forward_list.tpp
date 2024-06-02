#include "forward_list.hpp"
template<typename T>
forward_list<T>::Node::Node() : ptr(nullptr) {}
    
template<typename T>
forward_list<T>::Node::Node(const T& t, Node* p) : obj(t), ptr(p) {}

template<typename T>
typename forward_list<T>::Node* forward_list<T>::Node::next() { return ptr;} //  typename?

template<typename T>
forward_list<T>::forward_list():head(nullptr){}

template<typename T>
void forward_list<T>::push_front(const T& obj) {
    head = new Node(obj, head);
}
template<typename T>
void forward_list<T>::push_back(const T& obj){
    if(!head){
        push_front(obj);
    }
    else{
        Node* temp = head;
        while (temp->next())
            temp = temp->next();
        Node* newnode = new Node(obj,nullptr);
        temp->ptr = newnode;
    }
}
template<typename T>
void forward_list<T>::display() const {
    Node* reader = head;
    while (reader) {
        std::cout << reader->obj << std::endl;
        reader = reader->next();
    }
}
template<typename T>
void forward_list<T>:: pop_front(){
    if (head) {
        Node* temp = head;
        head = head->next();
        delete temp;
    }
}
template<typename T>
void forward_list<T>::insert(const T& obj, const int& index){
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
    Node* newnode = new Node(obj, temp->next());
    temp->ptr = newnode;
}
template<typename T>
bool forward_list<T>::empty(){
    return head == nullptr;
}

template<typename T>
void forward_list<T>::make_cycle(){
    if(!head){
        return;
    }
    else{
        Node* temp = head;
        while (temp->next())
            temp = temp->next();
        temp->ptr = head;
    }
}
template<typename T>
bool forward_list<T>::has_cycle(){
    if (!head){
        return false;
    }
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(ptr2 && ptr2->next()){
        ptr1 = ptr1->next();
        ptr2 = ptr2->next()->next();
        if(ptr1 == ptr2){
            return true;
        }
    }
    return false;
}
template<typename T>
forward_list<T>::~forward_list() {
    if(has_cycle()){
        std::cerr << "Cannot delete list with cycle" << std::endl;
        return;
    }
        while (head) {
            Node* temp = head;
            head = head->next();
            delete temp;
        }
}
