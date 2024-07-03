//63: Գրել ֆունկցիա որը 0-10 միջակայքում կնտրի որևէ ռանդոմ թիվ, և կստեղծի այդ խորությամբ tree և ամեն tree-ի node-ը ևս կունենա ռանդոմ քանակութայմբ էլէմենտներ, այնուհետև շրջանցել այդ tree-ն layer by layer.
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
template <typename T>
struct Node
{
  std::vector<Node*> node_vec;
  T val;
  void push(Node<T>* node)
  {
    node_vec.push_back(node);
  }
  Node(T val) : val(val){}
};

template <typename T>
class Tree
{
  Node<T>* root;
public:
    Tree() : root(nullptr) {
           std::srand(std::time(nullptr));
           int depth = (std::rand() % 11); 
           if (depth == 0) return; 

           root = new Node<T>((std::rand() % 100)); 
           std::queue<Node<T>*> q;
           q.push(root);
           int current_depth = 1;

           while (!q.empty() && current_depth < depth) {
               int level_size = q.size();
               for (int i = 0; i < level_size; ++i) {
                   Node<T>* temp_n = q.front();
                   q.pop();
                   int num_children = (std::rand() % 5); 
                   for (int j = 0; j < num_children; ++j) {
                       Node<T>* child = new Node<T>((std::rand() % 100));
                       temp_n->push(child);
                       q.push(child);
                   }
               }
               ++current_depth;
           }
       }
    void traverse() {
           if (!root) return; 

           std::queue<Node<T>*> q;
           q.push(root);
           while (!q.empty()) {
               Node<T>* temp = q.front();
               std::cout << temp->val << " ";
               q.pop();
               for (auto* in : temp->node_vec) {
                   q.push(in);
               }
               
           }
           std::cout << std::endl;
       }

   ~Tree() {
       std::queue<Node<T>*> q;
       if (root) q.push(root);
       while (!q.empty()) {
           Node<T>* temp = q.front();
           q.pop();
           for (auto* in : temp->node_vec) {
               q.push(in);
           }
           delete temp;
       }
   }
  
};
int main() {
    
    Tree<int> my_tree;
    my_tree.traverse();
    return 0;
}
