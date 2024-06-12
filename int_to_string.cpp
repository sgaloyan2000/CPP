#include <iostream>
#include "stack"
#include "string"
void int_to_str(const int& input){
    if(input == 0){
        std::cout<<"zero "<<std::endl;
        return;
    }
    std::stack<int> my_stack;
    int temp = input;
    while(temp){
        my_stack.push(temp%10);
        temp /= 10;
    }
    bool two_digit_1 = false;
    bool two_digit_others = false;
    while (!my_stack.empty()){
        switch (my_stack.size()) {
            case 4:
                switch (my_stack.top()) {
                    case 0:
                        break;
                    case 1:
                        std::cout<<"one thousand ";
                        break;
                    case 2:
                        std::cout<<"two thousand ";
                        break;
                    case 3:
                        std::cout<<"three thousand ";
                        break;
                    case 4:
                        std::cout<<"four thousand ";
                        break;
                    case 5:
                        std::cout<<"five thousand ";
                        break;
                    case 6:
                        std::cout<<"six thousand ";
                        break;
                    case 7:
                        std::cout<<"seven thousand ";
                        break;
                    case 8:
                        std::cout<<"eight thousand ";
                        break;
                    case 9:
                        std::cout<<"nine thousand ";
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (my_stack.top()) {
                    case 0:
                        break;
                    case 1:
                        std::cout<<"one hundred ";
                        break;
                    case 2:
                        std::cout<<"two hundred ";
                        break;
                    case 3:
                        std::cout<<"three hundred ";
                        break;
                    case 4:
                        std::cout<<"four hundred ";
                        break;
                    case 5:
                        std::cout<<"five hundred ";
                        break;
                    case 6:
                        std::cout<<"six hundred ";
                        break;
                    case 7:
                        std::cout<<"seven hundred ";
                        break;
                    case 8:
                        std::cout<<"eight hundred ";
                        break;
                    case 9:
                        std::cout<<"nine hundred ";
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                two_digit_others = true;
                switch (my_stack.top()) {
                    case 0:
                        break;
                    case 1:
                        two_digit_1 = true;
                        break;
                    case 2:
                        std::cout<<"twenty ";
                        break;
                    case 3:
                        std::cout<<"thirty ";
                        break;
                    case 4:
                        std::cout<<"forty ";
                        break;
                    case 5:
                        std::cout<<"fifty ";
                        break;
                    case 6:
                        std::cout<<"sixty ";
                        break;
                    case 7:
                        std::cout<<"seventy ";
                        break;
                    case 8:
                        std::cout<<"eighty ";
                        break;
                    case 9:
                        std::cout<<"ninety ";
                        break;
                    default:
                        break;
                }
                break;
            case 1:
                if(two_digit_1){
                    switch (my_stack.top()) {
                        case 0:
                            std::cout<<"ten ";
                            break;
                        case 1:
                            std::cout<<"eleven ";
                            break;
                        case 2:
                            std::cout<<"twelve ";
                            break;
                        case 3:
                            std::cout<<"thirteen ";
                            break;
                        case 4:
                            std::cout<<"fourteen ";
                            break;
                        case 5:
                            std::cout<<"fifteen ";
                            break;
                        case 6:
                            std::cout<<"sixteen ";
                            break;
                        case 7:
                            std::cout<<"seventeen ";
                            break;
                        case 8:
                            std::cout<<"eighteen ";
                            break;
                        case 9:
                            std::cout<<"nineteen ";
                            break;
                        default:
                            break;
                    }
                }
                else
                    {
                        switch (my_stack.top()) {
                            case 0:
                                if(two_digit_others){
                                    break;
                                }
                                else{
                                    std::cout<<"zero";
                                    break;
                                }
                            case 1:
                                std::cout<<"one ";
                                break;
                            case 2:
                                std::cout<<"two ";
                                break;
                            case 3:
                                std::cout<<"three ";
                                break;
                            case 4:
                                std::cout<<"four ";
                                break;
                            case 5:
                                std::cout<<"five ";
                                break;
                            case 6:
                                std::cout<<"six ";
                                break;
                            case 7:
                                std::cout<<"seven ";
                                break;
                            case 8:
                                std::cout<<"eight ";
                                break;
                            case 9:
                                std::cout<<"nine ";
                                break;
                            default:
                                break;
                    }
                }
                break;
            default:
                std::cout<<"Input number is too long"<<std::endl;
                return;
        }
        my_stack.pop();
    }
    std::cout<<std::endl;
}

int main() {
    int_to_str(1);
    int_to_str(0);
    int_to_str(10);
    int_to_str(112);
    int_to_str(450);
    int_to_str(999);
    int_to_str(4124);
    int_to_str(8000);
    int_to_str(99952);

    return 0;
}
