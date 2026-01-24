#include <iostream>

float get_float(){
    
    float x{};
    std::cout << "Please enter a value: ";
    std::cin >> x;

    return x;
}

char get_operator(){
    
    char x{};
    std::cout << "Please choose an operator - '+', '-', '*', '/'";
    std::cin >> x;

    return x;
}

float calc_value(float x, float y, char op){
    
    float val{};

    switch (op){
        case '+':
            val = x + y;
            break;

        case '-':
            val = x - y;
            break;

        case '*':
            val = x * y;
            break;

        case '/':
            val = x / y;
            break;

        default:
            break;
    }

    return val;

}

int main(){

    float x{get_float()};
    float y{get_float()};
    char op{get_operator()};

    float val{calc_value(x, y, op)};

    std::cout << x << " " << op << " " << y << " is " << val;


    return 0;
}