// custom class hashing


#include <iostream>
#include <unordered_map>
#include <functional>
struct car {
    int speed;
    int horse_power;
    std::string name;
public:
    car():speed(0),horse_power(0),name(""){}
    car(int s, int hp, std::string n):speed(s), horse_power(hp), name(n){}
    bool operator == (const car& obj)const{
        return (speed == obj.speed) && (horse_power == obj.horse_power) && (name == obj.name);
    }
};
struct my_hash{
    size_t operator ()(const car& obj)const{
        return std::hash<int>()(obj.speed) ^ (std::hash<int>()(obj.horse_power) << 1) ^ (std::hash<std::string>()(obj.name)<<2);
    }
};
int main() {
    car bmw(280,300,"BMW");
    car mercedes (250,250,"Mercedes");
    std::unordered_map<car, std::string,my_hash> my_map;
    my_map[bmw] = "Stive";
    my_map[mercedes] = "Jhon";
    for (const auto& pair : my_map) {
            std::cout << "Car: " << pair.first.name << " - Owner: " << pair.second << std::endl;
        }
    return 0;
}
