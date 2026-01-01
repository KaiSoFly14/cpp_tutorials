// This is an implementation of the Thomas Algorithm to solve TriDiagnol Matrices

#include <vector>
#include <iostream>

std::vector<double> tridiag(
    std::vector<double> a, // lower diagnol
    std::vector<double> b, // diagnol
    std::vector<double> c, // upper diagnol
    std::vector<double> d, // solution
    std::size_t n                  // size
    ) {
    
    std::vector<double> c_prime (n, 0.0);
    std::vector<double> d_prime (n, 0.0);

    c_prime[0] = c[0]/b[0];
    d_prime[0] = d[0]/b[0];

    for (std::size_t i = 1; i <= n - 2; i++) {
        c_prime[i] = c[i] / (b[i] - a[i] * c_prime[i-1]);
    }

    for (std::size_t i = 1; i <= n -1; i++) {
        d_prime[i] = (d[i] - a[i] * d_prime[i-1]) / 
                     (b[i] - a[i] * c_prime[i-1]);
    }
    
    std::vector<double> x (n, 0.0); // Solved for eigen vector

    x[n-1] = d_prime[n-1];
    for (std::size_t i = n - 1; i >= 1; i--){
        x[i-1] = d_prime[i-1] - c_prime[i-1] * x[i];
    }   

    return x;
}