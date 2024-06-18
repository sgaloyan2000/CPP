//
//  bst.hpp
//  BST
//
//  Created by Serzh Galoyan on 18.06.24.
//

#ifndef bst_hpp
#define bst_hpp
template<typename T>
class bst{
public:
    struct Node {
        Node* ptr_left;
        Node* ptr_right;
        T obj;
        Node();
        Node(const T&);
        Node* left();
        Node* right();
    };
    bst();
    void push(const T&);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void layer_by_layer() const;
    bool empty()const;
    ~bst();
private:
    Node* root;
    void delete_tree(Node*);
    void inorder_helper(Node*) const;
    void preorder_helper(Node*) const;
    void postorder_helper(Node*) const;
};
#include "bst.tpp"
#include <stdio.h>

#endif /* bst_hpp */
