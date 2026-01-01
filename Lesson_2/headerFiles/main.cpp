#include <iostream>
#include "input.h"
#include "math.h"

int main(){

    float x{getUserInput()};
    float y{getUserInput()};

    std::cout << "The sum of "<< x << " and " << y << " is: " << add(x,y) << '\n';
    std::cout << "The product of "<< x << " and " << y << " is: " << mult(x,y) << '\n';
    return 0;
}