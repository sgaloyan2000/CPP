#include <iostream>

class animal{
    static int count;
public:
    animal (){
        count++;
    }
    virtual ~animal (){}
    static int get_count(){
        return count;
    }
    virtual void voice() = 0;
};

int animal::count = 0;

class dog:public animal{
public:
    dog(){}
    ~dog(){}
    virtual void voice(){
        std::cout<<"shun - hachoc"<<std::endl;
    }
};
class cat:public animal{
public:
    cat(){}
    virtual ~cat(){}
    virtual void voice(){
        std::cout<<"katu - mlavoc"<<std::endl;
    }
};
class fish:public animal{
public:
    fish(){}
    virtual ~fish(){}
    virtual void voice(){
        std::cout<<"dzuk - yes dzayn chem hanum"<<std::endl;
    }
};
class lion:public animal{
public:
    lion(){}
    virtual ~lion(){}
    virtual void voice(){
        std::cout<<"aryuc - mrnchoc"<<std::endl;
    }
};
class wolf:public animal{
public:
    wolf(){}
    virtual ~wolf(){}
    virtual void voice(){
        std::cout<<"gayl - vornoc"<<std::endl;
    }
};

class zoo{
    static zoo* instance;
    animal* ptr[5];
    zoo(){}
public:
    zoo(const zoo& obj) = delete;
    zoo& operator = (const zoo& obj) = delete;
    static zoo* get_instance()
    {
        if(instance)
            return instance;
        else
        {
            instance = new zoo();
            return instance;
        }
    }
    void registration(dog* d, cat* c, fish* f, lion* l, wolf* w){
        ptr[0] = d;
        ptr[1] = c;
        ptr[2] = f;
        ptr[3] = l;
        ptr[4] = w;
    }
    void zoo_voices(){
        for(int i = 0; i < 5; ++i) {
            ptr[i]->voice();
        }
    }
    ~zoo()
    {
        delete instance;
    }
};

zoo* zoo::instance = nullptr;

int main()
{
    zoo* newzoo = zoo::get_instance();
    
    dog* d = new dog();
    cat* c = new cat();
    fish* f = new fish();
    lion* l = new lion();
    wolf* w = new wolf();
    
    newzoo->registration(d,c,f,l,w);
    newzoo->zoo_voices();
    
    std::cout<<animal::get_count()<<std::endl;
    
    
    delete d;
    delete c;
    delete f;
    delete l;
    delete w;
    
    return 0;
}
