//
//  bst.cpp
//  BST
//
//  Created by Serzh Galoyan on 18.06.24.
//

#include "bst.hpp"
#include <iostream>
#include <queue>
template<typename T>
bst<T>::Node::Node() : ptr_left(nullptr),ptr_right(nullptr) {}
    
template<typename T>
bst<T>::Node::Node(const T& t) : obj(t),ptr_left(nullptr), ptr_right(nullptr) {}

template<typename T>
typename bst<T>::Node* bst<T>::Node::left() { return ptr_left;}

template<typename T>
typename bst<T>::Node* bst<T>::Node::right() { return ptr_right;}

template<typename T>
bst<T>::bst():root(nullptr){}

template<typename T>
void bst<T>::push(const T& obj) {
    if(root){
        Node* temp = root;
        Node* temp2 = nullptr;
        while(temp){
            temp2 = temp;
            if(temp->obj >= obj){
                temp = temp->left();
            }
            else{
                temp = temp->right();
            }
        }
        Node* new_node = new Node(obj);
        if(temp2->obj >= obj){
            temp2->ptr_left = new_node;
        }
        else{
            temp2->ptr_right = new_node;
        }
    }
    else{
        Node* new_node = new Node(obj);
        root = new_node;
    }
}

template<typename T>
bool bst<T>::empty()const{
    return root == nullptr;
}
template<typename T>
void bst<T>::delete_tree(Node* node){
    if (node != nullptr) {
        delete_tree(node->ptr_left);
        delete_tree(node->ptr_right);
        delete node;
    }
}
template<typename T>
bst<T>::~bst() {
    delete_tree(root);
}
template<typename T>
void bst<T>::inorder() const {
    inorder_helper(root);
    std::cout << std::endl;
}
template<typename T>
void bst<T>::inorder_helper(Node* node) const {
    if (node) {
        inorder_helper(node->left());
        std::cout << node->obj << " ";
        inorder_helper(node->right());
    }
}
template<typename T>
void bst<T>::preorder() const {
    preorder_helper(root);
    std::cout << std::endl;
}
template<typename T>
void bst<T>::preorder_helper(Node* node) const {
    if (node) {
        std::cout << node->obj << " ";
        preorder_helper(node->left());
        preorder_helper(node->right());
    }
}
template<typename T>
void bst<T>::postorder() const {
    postorder_helper(root);
    std::cout << std::endl;
}
template<typename T>
void bst<T>::postorder_helper(Node* node) const {
    if (node) {
        postorder_helper(node->left());
        postorder_helper(node->right());
        std::cout << node->obj << " ";
    }
}
template<typename T>
void bst<T>::layer_by_layer() const {
    if (!root) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->obj << " ";

        if (current->ptr_left) q.push(current->ptr_left);
        if (current->ptr_right) q.push(current->ptr_right);
    }
    std::cout << std::endl;
}
