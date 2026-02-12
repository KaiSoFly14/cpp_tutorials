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
operator+(const double& a,
          const std::vector<double>& b){
            
    std::vector<double> result(b.size());

    for (std::size_t i = 0; i < b.size(); i++) {
        result[i] = a + b[i];
    }

    return result;
}

std::vector<double>
operator+(const std::vector<double>& a,
          const double& b){
            
    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] + b;
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

std::vector<double>
operator-(const double& a,
          const std::vector<double>& b){
            
    std::vector<double> result(b.size());

    for (std::size_t i = 0; i < b.size(); i++) {
        result[i] = a - b[i];
    }

    return result;
}

std::vector<double>
operator-(const std::vector<double>& a,
          const double& b){

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] - b;
    }

    return result;
}

std::vector<double>
operator*(const std::vector<double>& a,
          const std::vector<double>& b){
            
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vector sizes must match");
    }

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] * b[i];
    }

    return result;
}

std::vector<double> 
operator*(const double& a, 
          const std::vector<double>& b){

    std::vector<double> result(b.size());

    for (std::size_t i = 0; i < b.size(); i++) {
        result[i] = a * b[i];
    }

    return result;
}

std::vector<double> 
operator*(const std::vector<double>& a,
          const double& b){

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] * b;
    }

    return result;
}

std::vector<double>
operator/(const std::vector<double>& a,
          const std::vector<double>& b){
            
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vector sizes must match");
    }

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] / b[i];
    }

    return result;
}

std::vector<double> 
operator/(const double& a, 
          const std::vector<double>& b){

    std::vector<double> result(b.size());

    for (std::size_t i = 0; i < b.size(); i++) {
        result[i] = a / b[i];
    }

    return result;
}

std::vector<double> 
operator/(const std::vector<double>& a,
          const double& b){

    std::vector<double> result(a.size());

    for (std::size_t i = 0; i < a.size(); i++) {
        result[i] = a[i] / b;
    }

    return result;
}