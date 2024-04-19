#include <iostream>
#include <string>
class car{
    int year;
    std::string mark;
    double engine;
    std::string color;
    car(){
    }
public:
    car(int input_year, std::string input_mark, double input_engine, std::string input_color){
        if(1990<=input_year && input_year<=2024)
            year = input_year;
        else std::cout<<"Input data is not valid";
        if(input_mark == "Mercedes" || input_mark == "BMW")
            mark = input_mark;
        else std::cout<<"Input mark is not valid";
        if(input_engine<= 6 || input_engine >=1)
            engine = input_engine;
        else std::cout<<"Input engine power is not valid";
        if(input_color == "green" || input_color == "blue" || input_color == "red" || input_color == "black"|| input_color == "white")
            color = input_color;
        else std::cout<<"Input color is not valid";
    }
    void get_info(){
        std::cout<<"Dear user, you are driving "<<color<<" "<<mark<<" which is made in "<<year<<" ,and its engine power is "<<engine<<"."<<std::endl;
    }
};
int main() {
    car my_car(2020,"Mercedes",4,"red");
    my_car.get_info();

    return 0;
}