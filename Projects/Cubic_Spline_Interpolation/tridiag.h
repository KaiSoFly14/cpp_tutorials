#pragma once

#include <vector>

std::vector<double> tridiag(
    std::vector<double> a, // lower diagnol
    std::vector<double> b, // diagnol
    std::vector<double> c, // upper diagnol
    std::vector<double> d, // solution
    std::size_t n                  // size
    );