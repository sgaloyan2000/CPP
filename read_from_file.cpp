#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool isInteger(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool isDouble(std::string& str) {
    int decimalPointCount = 0;

    for (char& c : str) {
        if(c == ','){
            if(decimalPointCount>0){
                return false; //more than one decimalpoint
            }
            c = '.';
            decimalPointCount++;
        }
        else if (!std::isdigit(c)){
            return false; //not a number
        }
    }
    return true;
}

struct what_is_the_type{
    union type_{
        std::string* s;
        int i;
        double d;
    }; type_ type;
    
    what_is_the_type(int i)
    {
        type.i = i;
        std::cout<<"The type is int: "<<i<<std::endl;

    }
    what_is_the_type(double d)
    {
        type.d = d;
        std::cout<<"The type is double: "<<d<<std::endl;
    }
    what_is_the_type(std::string s)
    {
        type.s = &s;
        std::cout<<"The type is string: "<<s<<std::endl;
    }
};


int main() {
    std::ifstream file("/Users/Serzh/Downloads/input.txt/TXT.txt");
    
    
    if (!file.is_open())
    {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if(line.empty()){
            continue;
        }
        std::cout<<line<<std::endl;
        if(isInteger(line)){
            what_is_the_type(std::stoi(line));
        }
        else if(isDouble(line)){
            what_is_the_type(std::stod(line));
        }
        else
            what_is_the_type(std::string(line));
    }
    

    return 0;
}
