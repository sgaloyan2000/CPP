#include <iostream>
#include <string>

class vehicle{
    int year;
public:
    virtual void type() = 0;
    virtual void mark() = 0;
    vehicle(){}
    vehicle(int input_year):year(input_year){}
    virtual ~vehicle(){}
};

class car:public vehicle{
    std::string mark;
public:
    car(){}
    car(int input_year, std::string input_mark):vehicle(input_year),mark(input_mark){}
    ~car(){}
};
class bus:public vehicle{
    int seats;
public:
    bus(){}
    bus(int input_year, int input_seats):vehicle(input_year),seats(input_seats){}
    ~bus(){}
};
class tank:public vehicle{
    int ammo;
public:
    tank(){}
    tank(int input_year,int input_ammo):vehicle(input_year),ammo(input_ammo){}
    ~tank(){}
};
class sedan:public car{
    bool gas;
public:
    virtual void type(){
        std::cout<<"Car"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"sedan"<<std::endl;
    }
    sedan(){}
    sedan(int input_year, std::string input_mark, bool is_gas):car(input_year,input_mark),gas(is_gas){}
    ~sedan(){}
};
class jeep:public car{
    double wheels_diameter;
public:
    virtual void type(){
        std::cout<<"Car"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"jeep"<<std::endl;
    }
    jeep(){}
    jeep(int input_year,std::string input_mark, double input_diameter):
    car(input_year,input_mark),wheels_diameter(input_diameter){}
    ~jeep(){}
};
class electro:public car{
    bool automatic;
public:
    virtual void type(){
        std::cout<<"Car"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"electro"<<std::endl;
    }
    electro(){}
    electro(int input_year,std::string input_mark, bool input_automatic):car(input_year,input_mark),
    automatic(input_automatic){}
    ~electro(){}
};
class two_stage:public bus{
    std::string color;
public:
    virtual void type(){
        std::cout<<"Bus"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"two_stage"<<std::endl;
    }
    two_stage(){}
    two_stage(int input_year,int input_seats,std::string input_color):
    bus(input_year,input_seats),color(input_color){}
    ~two_stage(){}
};
class micro:public bus{
    bool conditioner;
public:
    virtual void type(){
        std::cout<<"Bus"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"micro"<<std::endl;
    }
    micro(){}
    micro(int input_year,int input_seats,bool input_conditioner):bus(input_year,input_seats),
    conditioner(input_conditioner){}
    ~micro(){}
};
class tour:public bus{
    std::string direction;
public:
    virtual void type(){
        std::cout<<"Bus"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"tour"<<std::endl;
    }
    tour(){}
    tour(int input_year,int input_seats,std::string input_direction):bus(input_year,input_seats),direction(input_direction){}
    ~tour(){}
};

class armada: public tank{
    bool rocket;
public:
    virtual void type(){
        std::cout<<"Tank"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"armada"<<std::endl;
    }
    armada(){}
    armada(int input_year,int input_ammo,bool input_rocket):tank(input_year,input_ammo),rocket(input_rocket){}
    ~armada(){}
};

class panzer: public tank{
    bool gun;
public:
    virtual void type(){
        std::cout<<"Tank"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"panzer"<<std::endl;
    }
    panzer(){}
    panzer(int input_year,int input_ammo,bool input_gun):tank(input_year,input_ammo),gun(input_gun){}
    ~panzer(){}
};
class T30: public tank{
    bool armor;
public:
    virtual void type(){
        std::cout<<"Tank"<<std::endl;
    }
    virtual void mark(){
        std::cout<<"T30"<<std::endl;
    }
    T30(){}
    T30(int input_year,int input_ammo,bool input_armor):tank(input_year,input_ammo),armor(input_armor){}
    ~T30(){}
};
int main() {
    sedan bmw;
    jeep range_rover;
    electro tesla;
    two_stage bus_2stage;
    micro micro_bus;
    tour tour_bus;
    armada tank_armada;
    panzer tank_panzer;
    T30 tank_T30;
    vehicle* ptr[3];
    ptr[0] = &bmw;
    ptr[1] = &range_rover;
    ptr[2] = &tesla;
    for (int i=0; i<3; i++){
        ptr[i]->mark();
        ptr[i]->type();
    }
    return 0;
}
