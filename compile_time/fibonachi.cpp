#include <iostream>
template <unsigned char f>
class Fibonachi{
    public:
    static const unsigned long long val = (Fibonachi<f-1>::val + Fibonachi<f-2>::val);
};
template<>
class Fibonachi<0>
{
    public:
    static const unsigned long long val = 1;
};
template<>
class Fibonachi<1>
{
    public:
    static const unsigned long long val = 1;
};
int main()
{
    std::cout<<Fibonachi<5>::val<<std::endl;

    return 0;
}
