#include <iostream>

int add(int x, int y);
int getUserInput();

int main(){
    int x{getUserInput()};
    int y{getUserInput()};

    std::cout << "The sum of "<< x << " and " << y << " is: " << add(x,y) << '\n';
    return 0;
}