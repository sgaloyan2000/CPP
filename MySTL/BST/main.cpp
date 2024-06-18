#include "bst.hpp"
int main() {
    bst<int> tree;
    tree.push(5);
    tree.push(3);
    tree.push(7);
    tree.push(2);
    tree.push(4);
    tree.push(6);
    tree.push(8);
    std::cout << "Inorder: ";
    tree.inorder();
    std::cout << "Preorder: ";
    tree.preorder();
    std::cout << "Postorder: ";
    tree.postorder();
    std::cout << "layers: ";
    tree.layer_by_layer();
    return 0;
}
/*
         5
      3      7
    2   4  6   8
 */
