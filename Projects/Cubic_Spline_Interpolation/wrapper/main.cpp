#include <iostream>
#include <vector>
#include "../operators.h"
#include "../vector_feature.h"

int main(){

    std::vector<double> x{2.0};
    std::vector<double> y{2.0};

    printVector(x+y);

    

    return 0;
}