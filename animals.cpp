#include <iostream>
class animal{
public:
    animal (){ std:: cout << __func__<< std::endl;}
    virtual ~animal (){ std:: cout << __func__<< std::endl;}
    virtual void voice() = 0;
};
class dog:public animal{
public:
    dog(){ std:: cout << __func__<< std::endl;}
    ~dog(){ std:: cout << __func__<< std::endl;}
    virtual void voice(){
        std::cout<<"shun - hachoc"<<std::endl;
    } 
};
class cat:public animal{
public:
    cat(){ std:: cout << __func__<< std::endl;}
    virtual ~cat(){ std:: cout << __func__<< std::endl;}
    virtual void voice(){
        std::cout<<"katu - mlavoc"<<std::endl;
    } 
};
class fish:public animal{
public:
    fish(){ std:: cout << __func__<< std::endl;}
    virtual ~fish(){ std:: cout << __func__<< std::endl;}
    virtual void voice(){
        std::cout<<"dzuk - yes dzayn chem hanum"<<std::endl;
    } 
};
class lion:public animal{
public:
    lion(){ std:: cout << __func__<< std::endl;}
    virtual ~lion(){ std:: cout << __func__<< std::endl;}
    virtual void voice(){
        std::cout<<"aryuc - mrnchoc"<<std::endl;
    } 
};
class wolf:public animal{
public:
    wolf(){ std:: cout << __func__<< std::endl;}
    virtual ~wolf(){ std:: cout << __func__<< std::endl;}
    virtual void voice(){
        std::cout<<"gayl - vornoc"<<std::endl;
    } 
};
int main()
{   
    animal* ptr[5];
    ptr[0] = new dog();
    ptr[1] = new cat();
    ptr[2] = new fish();
    ptr[3] = new lion();
    ptr[4] = new wolf();
    
    for(int i = 0; i < 5; ++i) {
        ptr[i]->voice();
    }
    
    for(int i = 0; i < 5; ++i) {
        delete ptr[i];
    }
    return 0;
}
