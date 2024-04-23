#include <iostream>
#include <string>
class wheel{
  double m_diameter;
  bool m_winter; //true if winter, false if summer
public:
    wheel(){
        m_diameter = 16;
        m_winter = true;
    }
    wheel(double diameter, bool winter):m_diameter(diameter),m_winter(winter){
        
    }
    void info(){
        std::cout<<"Diameter of wheels are - "<<m_diameter<<std::endl;
        if (m_winter)
            std::cout<<"You can drive if outside is winter"<<std::endl;
        else
            std::cout<<"You can drive if outside is summer"<<std::endl;
    }
    void change_diameter(double new_diameter){
        if(new_diameter>14 && new_diameter <22)
            m_diameter = new_diameter;  
        else
            std::cout<<"There is no such Diameter"<<std::endl;
    }
    void switch_wheels(){
        m_winter = !m_winter;
    }
    
};
class car{
    int year;
    std::string mark;
    double engine;
    std::string color;
    wheel wheels;
    
public:
    car(){}
    car(int input_year, std::string input_mark, double input_engine, std::string input_color){
        if(1990<=input_year && input_year<=2024)
            year = input_year;
        else std::cout<<"Input data is not valid";
        if(input_mark == "Mercedes" || input_mark == "BMW")
            mark = input_mark;
        else std::cout<<"Input mark is not valid";
        if(input_engine<= 6 && input_engine >=1)
            engine = input_engine;
        else std::cout<<"Input engine power is not valid";
        if(input_color == "green" || input_color == "blue" || input_color == "red" ||
        input_color == "black" || input_color == "white")
            color = input_color;
        else std::cout<<"Input color is not valid";
    }
    void get_info(){
        std::cout<<"Dear user, you are driving "<<color<<" "<<mark<<" which is made in "<<year<<" ,its engine power is "
        <<engine<<", wheels: ";
        wheels.info();
    }
    void change_diameter(double new_diameter){
        wheels.change_diameter(new_diameter);
    }
    void switch_wheels(){
        wheels.switch_wheels();
    }
};
class parking{
  car** cars;
  int size;
  int ocupied;
 public:
    parking(){
        size = 0;
        ocupied = 0;
        cars = nullptr;
    }
    parking(int size_){
        cars = new car*[size_];
        size = size_;
        ocupied = 0;
    }
    parking (const parking& obj){
        size = obj.size;
        ocupied = obj.ocupied;
        cars = new car*[size];
        for (int i=0; i<size; i++){
            cars[i] = new car(*obj.cars[i]);
        }
    }
    parking& operator=(const parking& obj) {
        if (this != &obj) {
    
            delete[] cars;

            size = obj.size;
            ocupied = obj.ocupied;
    
            cars = new car*[size];
            for (int i = 0; i < size; ++i) {
                cars[i] = new car(*obj.cars[i]);
            }
        }
        return *this;
    }
    ~parking(){
        // for (int i = 0; i < size; i++)
        //     delete cars[i];
        delete[] cars;
    }

    void push(car* new_car){
        if(ocupied < size){
            cars[ocupied] = new_car;
            ocupied++;
            std::cout << "Car added successfully." << std::endl;
            std::cout << ocupied<<" from "<<size<<" slots are ocupied" << std::endl;
        }
        else std::cout<<"There is no free parking slot"<<std::endl;
    }
    void pop(){
        if(ocupied > 0){
            std::cout << "Removing car from parking slot " << ocupied - 1 << std::endl;
            //delete cars[ocupied-1]; 
            cars[ocupied-1] = nullptr;
            ocupied--;
            std::cout << "Car removed successfully." << std::endl;
        }
        else std::cout << "Parking slot is empty" << std::endl;
    }

    void parking_info(){
        if(ocupied){
            for (int i=0;i<size;i++)
                cars[i]->get_info();
        }
        else std::cout<<"There is no cars in parking"<<std::endl;
    }
    
};
int main() {
    car my_car1(2020,"Mercedes",4,"red");
    car* car_1 = &my_car1;
    car my_car2(2002,"Mercedes",3,"green");
    car* car_2 = &my_car2;
    car my_car3(2019,"BMW",2,"black");
    car* car_3 = &my_car3;
    car my_car4(2012,"Mercedes",1.5,"white");
    car* car_4 = &my_car4;
    car my_car5(2022,"BMW",5,"red");
    car* car_5 = &my_car5;
    car my_car6(2007,"BMW",2,"white");
    car* car_6 = &my_car6;
    parking park(5);
    park.push(car_1);
    park.push(car_2);
    park.push(car_3);
    park.push(car_4);
    park.push(car_5);
    park.push(car_6);
    park.pop();
    park.push(car_6);
    park.parking_info();
    return 0;
}
