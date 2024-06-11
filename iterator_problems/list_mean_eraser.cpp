#include <iostream>
#include <list>
//52: Գրել ֆունկցիա որը օգտագործելով iterator-ներ կջնջի list-ի միջի այն թվերը, որոնք փոքր են այդ list-ի թվերի միջին թվաբանականից.

template <class T>
void printer(const std::list<T>& l){
    for(auto i = l.begin(); i != l.end();++i){
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}

int mean (const std::list<int>& l){
    int m = 0;
    for(auto i = l.begin(); i != l.end();++i){
        m += *i;
    }
    return m/l.size();
}
void eraser(std::list<int>& l, int mean){
    for(auto i = l.begin(); i != l.end();){
        if(*i<mean){
            i = l.erase(i);
        }
        else{
            i++;
        }
    }
}
int main() {
    std::list<int> my_list {1,4,6,7,2,3,5,6,1,7,3,12,41};
    printer(my_list);
    eraser(my_list, mean(my_list));
    printer(my_list);
    
    return 0;
}
