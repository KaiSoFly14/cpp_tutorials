#include <iostream>

int readNumber(){
    std::cout << "Enter an integer: ";
    int num{};
    std::cin >> num;

    return num;
}

void writeAnswer(int x){
    std::cout << "The sum is: " << x << '\n';
}