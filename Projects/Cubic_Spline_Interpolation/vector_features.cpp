#include <vector>
#include <iostream>

void printVector(const std::vector<double>& v) {
    for (double value : v) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

std::vector<double> linspace(double start, double stop, std::size_t num){
    std::vector<double> result(num, 0.0);

    double step = (stop - start) / (num - 1.0);
    
    for (std::size_t i = 0; i < num; i++) {
        result[i] = start + i * step;
    }

    return result;
}