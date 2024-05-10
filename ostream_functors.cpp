#include <iostream>
class f{
    int count = 0;
public:
    f& operator () (){
        count++;
        return *this;
    }
   friend std::ostream& operator << (std::ostream& os, const f& obj);
};
std::ostream& operator << (std::ostream& os, const f& obj){
    os<<obj.count;
    return os;
}
int main()
{
    std::cout<<f()<<std::endl;
    std::cout<<f()()<<std::endl;
    std::cout<<f()()()<<std::endl;
    std::cout<<f()()()()<<std::endl;

    return 0;
}
