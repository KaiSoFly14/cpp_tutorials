#include <vector>
#include <iostream>

#include "csv_write.h"
#include "cubicSpline.h"

int main(){
    std::vector<double> x {-2, 0, 3, 4};   // knot positions
    std::vector<double> y {-2, 1, 0, 3};   // data values
    std::size_t n {4};                   // number of points

    std::vector<std::vector<double>> all_vectors = {cubicSpline(x,y,n)};
    writeVectorsToCSV("output.csv", all_vectors);

    return 0;
}