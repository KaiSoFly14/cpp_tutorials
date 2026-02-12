#include <vector>
#include <iostream>

#include "tridiag.h"
#include "vector_feature.h"
#include "operators.h"
#include "csv_write.h"

int main(){
    std::vector<double> x {-2, 0, 3, 4};   // knot positions
    std::vector<double> y {-2, 1, 0, 3};   // data values
    std::size_t n {4};                   // number of points

    std::vector<double> h(n-1);

    for (std::size_t i = 0; i < n-1; i++){
        h[i] = x[i + 1] - x[i];
    }

    std::vector<double> lower(n, 0.0);
    std::vector<double> diag(n, 0.0);
    std::vector<double> upper(n, 0.0);
    std::vector<double> rhs(n, 0.0);

    for (std::size_t i = 1; i <= n - 2; i++) {
        lower[i] = h[i - 1];
        diag[i]  = 2.0 * (h[i - 1] + h[i]);
        upper[i] = h[i];

        rhs[i] = 3.0 * (
            (y[i + 1] - y[i]) / h[i]
        - (y[i] - y[i - 1]) / h[i - 1]
        );
    }

    diag[0] = 1.0;
    diag[n - 1] = 1.0;

    rhs[0] = 0.0;
    rhs[n - 1] = 0.0;

    std::vector<double> c{tridiag(lower, diag, upper, rhs, n)}; // calculate curvature

    // build coefficients of spline
    std::vector<double> a = y;

    std::vector<double> b(n - 1);
    for (std::size_t i = 0; i < n - 1; i++) {
        b[i] = (y[i + 1] - y[i]) / h[i]
            - h[i] * (2.0 * c[i] + c[i + 1]) / 3.0;
    }

    std::vector<double> d(n - 1);
    for (std::size_t i = 0; i < n - 1; i++) {
        d[i] = (c[i + 1] - c[i]) / (3.0 * h[i]);
    }


    std::vector<double> x_final{};
    std::vector<double> y_final{};

    for (std::size_t i = 0; i < x.size()-1; i++){
        double dif {x[i+1] - x[i]};
        std::vector<double> yeet = linspace(x[i], x[i+1], dif*10 + 1);
        std::vector<double> yote = a[i] + b[i] * (yeet - x[i]) + c[i] * (yeet - x[i])*(yeet - x[i]) + d[i] * (yeet - x[i])*(yeet - x[i])*(yeet - x[i]);

        // printVector(yote);

        x_final.insert(x_final.end(), yeet.begin(), yeet.end());
        y_final.insert(y_final.end(), yote.begin(), yote.end());
        
    }

    printVector(x_final);
    printVector(y_final);
    
    std::vector<std::vector<double>> all_vectors = {x_final, y_final};
    writeVectorsToCSV("output.csv", all_vectors);

    return 0;
}