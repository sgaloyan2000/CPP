#include <iostream>
struct animal{
    virtual void type()=0;
    animal()
    {
        m_age = 0;
        std::cout<<__func__<<std::endl;
    }
    animal(int age):m_age(age)
    {
        std::cout<<__func__<<std::endl;
    }
    virtual ~animal()
    {
        std::cout<<__func__<<std::endl;
    }
private:
    int m_age;
};

struct ground_animal:virtual animal{
    ground_animal()
    {
        std::cout<<__func__<<std::endl;
    }
    ground_animal(int age):animal(age)
    {
        std::cout<<__func__<<std::endl;
    }
    ~ground_animal()
    {
        std::cout<<__func__<<std::endl;
    }
    void type()
    {
        std::cout<<"Ground animal"<<std::endl;
    }
};
struct fish:virtual animal{
    fish()
    {
        std::cout<<__func__<<std::endl;
    }
    fish(int age):animal(age)
    {
        std::cout<<__func__<<std::endl;
    }
    ~fish()
    {
        std::cout<<__func__<<std::endl;
    }
    void type()
    {
        std::cout<<"Fish"<<std::endl;
    }
};
struct amphibian: ground_animal, fish{
    amphibian()
    {
        std::cout<<__func__<<std::endl;
    }
    amphibian(int age):animal(age)
    {
        std::cout<<__func__<<std::endl;
    }
    ~amphibian()
    {
        std::cout<<__func__<<std::endl;
    }
    void type()
    {
        std::cout<<"Amphibian"<<std::endl;
    }
};

int main(){
    amphibian turtle(10);
    turtle.type();
    return 0;
}
