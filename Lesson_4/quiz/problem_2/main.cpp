#include <iostream>

float get_conditions(){

    float x{};
    
    std::cout << "Enter Tower Height (in meters): ";
    std::cin >> x;

    return x;
}

float calc_position(float height, float time){

    float grav{9.8};

    float x = height - grav * time * time / 2;

    return x;
}


int main(){

    float height {get_conditions()};

    for (int i = 0; i < 5; i++){
        
        std::cout << "Ball height at " << i << " seconds: " << calc_position(height, static_cast<float>(i)) << '\n';
    }

    return 0;

}