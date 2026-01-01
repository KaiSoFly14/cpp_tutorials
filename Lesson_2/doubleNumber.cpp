#include <iostream>

int doubleNumber(int x){
    return x*2;
}

int main(){
    int val;
    std::cout << "Enter an integer: ";
    std::cin >> val;
    std::cout << "Doubled value: " << doubleNumber(val) ;
    return 0;
}