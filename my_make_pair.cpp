#include <iostream>
template <typename K,typename V>
struct my_pair{
    K key;
    V value;
    my_pair() = default;
    my_pair(K k, V v):key(k), value(v){}
    void display(){
        std::cout<<"key: "<<key<<" -> value: "<<value<<std::endl;
    }
};
template <typename K,typename V>
my_pair<K, V> my_make_pair(K key, V value){
    return my_pair<K, V>(key,value);
}
int main() {
    my_pair<int, std::string> x = my_make_pair(1, std::string("something"));
    x.display();
    return 0;
}
