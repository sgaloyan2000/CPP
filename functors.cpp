#include <iostream>
class A{
    int a,b,c;
public:
    A()
    {
        a=0;
        b=0;
        c=0;
    }
    A(int x, int y, int z):a(x),b(y),c(z){}
    void operator() ()
    {
        std::cout<<"x = "<<a<<" y = "<<b<<" z = "<<c<<std::endl;
    }
    int operator() (bool cond)
    {
        if (cond)
            return a*b*c;
        else
            return 0;
    }
    int operator() (int d){
        return (a+b+c)/d;
    }
};
int main(){
    A a(2,4,6);
    a();
    std::cout<<a(true)<<std::endl;
    std::cout<<a(3)<<std::endl;
    return 0;
}
