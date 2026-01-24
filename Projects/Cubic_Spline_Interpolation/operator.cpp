#include <vector>
#include <iostream>

std::vector<double>
operator+(const std::vector<double>& a,
          const std::vector<double>& b){
            
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vector sizes must match");
    }

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] + b[i];
    }

    return result;
}

std::vector<double>
operator-(const std::vector<double>& a,
          const std::vector<double>& b){
            
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vector sizes must match");
    }

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] - b[i];
    }

    return result;
}