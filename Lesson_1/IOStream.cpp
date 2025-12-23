#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter Three Numbers: "; // ask user for a number

    int x{}, y{}, z{};       // define variables to hold user input (and value-initialize it)
    std::cin >> x >> y >> z; // get numbers from keyboard and store it in variables

    std::cout << "You entered " << x << ", " << y << ", and " << z << "." << std::endl;
    return 0;
}