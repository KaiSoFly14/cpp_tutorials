#include <iostream>

int main() {
    std::cout << "Hello, C++ with VS Code!" << std::endl;

    [[maybe_unused]] int a{};
    std::cout << a;

    return 0;
}