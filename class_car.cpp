#include <iostream>
#include <string>

class vehicle{
    int year;
    
public:
    vehicle()
    {
        std::cout<<__func__<<std::endl;
    }
    
    vehicle(int input_year):year(input_year)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~vehicle()
    {
        std::cout<<__func__<<std::endl;
    }

};

class car:public vehicle{
    std::string mark;
public:
    car()
    {
        std::cout<<__func__<<std::endl;
    }
    car(int input_year, std::string input_mark):vehicle(input_year),mark(input_mark)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~car()
    {
        std::cout<<__func__<<std::endl;
    }
};
class bus:public vehicle{
    int seats;
public:
    bus()
    {
        std::cout<<__func__<<std::endl;
    }
    bus(int input_year, int input_seats):vehicle(input_year),seats(input_seats)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~bus()
    {
        std::cout<<__func__<<std::endl;
    }
};
class tank:public vehicle{
    int ammo;
public:
    tank()
    {
        std::cout<<__func__<<std::endl;
    }
    tank(int input_year,int input_ammo):vehicle(input_year),ammo(input_ammo)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~tank()
    {
        std::cout<<__func__<<std::endl;
    }
};
class sedan:public car{
    bool gas;
public:
    sedan()
    {
        std::cout<<__func__<<std::endl;
    }
    sedan(int input_year, std::string input_mark, bool is_gas):car(input_year,input_mark),gas(is_gas)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~sedan()
    {
        std::cout<<__func__<<std::endl;
    }
};
class jeep:public car{
    double wheels_diameter;
public:
    jeep()
    {
        std::cout<<__func__<<std::endl;
    }
    jeep(int input_year,std::string input_mark, double input_diameter):
    car(input_year,input_mark),wheels_diameter(input_diameter)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~jeep()
    {
        std::cout<<__func__<<std::endl;
    }
};
class electro:public car{
    bool automatic;
public:
    electro()
    {
        std::cout<<__func__<<std::endl;
    }
    electro(int input_year,std::string input_mark, bool input_automatic):car(input_year,input_mark),
    automatic(input_automatic)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~electro()
    {
        std::cout<<__func__<<std::endl;
    }
};
class two_stage:public bus{
    std::string color;
public:
    two_stage()
    {
        std::cout<<__func__<<std::endl;
    }
    two_stage(int input_year,int input_seats,std::string input_color):
    bus(input_year,input_seats),color(input_color)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~two_stage()
    {
        std::cout<<__func__<<std::endl;
    }
};
class micro:public bus{
    bool conditioner;
public:
    micro()
    {
        std::cout<<__func__<<std::endl;
    }
    micro(int input_year,int input_seats,bool input_conditioner):bus(input_year,input_seats),
    conditioner(input_conditioner)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~micro()
    {
        std::cout<<__func__<<std::endl;
    }
};
class tour:public bus{
    std::string direction;
public:
    tour()
    {
        std::cout<<__func__<<std::endl;
    }
    tour(int input_year,int input_seats,std::string input_direction):bus(input_year,input_seats),
    direction(input_direction)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~tour()
    {
        std::cout<<__func__<<std::endl;
    }
};

class armada: public tank{
    bool rocket;
public:
    armada()
    {
        std::cout<<__func__<<std::endl;
    }
    armada(int input_year,int input_ammo,bool input_rocket):tank(input_year,input_ammo),rocket(input_rocket)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~armada()
    {
        std::cout<<__func__<<std::endl;
    }
};

class panzer: public tank{
    bool gun;
public:
    panzer()
    {
        std::cout<<__func__<<std::endl;
    }
    panzer(int input_year,int input_ammo,bool input_gun):tank(input_year,input_ammo),gun(input_gun)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~panzer()
    {
        std::cout<<__func__<<std::endl;
    }
};
class T30: public tank{
    bool armor;
public:
    T30()
    {
        std::cout<<__func__<<std::endl;
    }
    T30(int input_year,int input_ammo,bool input_armor):tank(input_year,input_ammo),armor(input_armor)
    {
        std::cout<<__func__<<" parametrized"<<std::endl;
    }
    ~T30()
    {
        std::cout<<__func__<<std::endl;
    }
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

    return 0;
}
