#pragma once
#include <vector>

std::vector<std::vector<double>> cubicSpline(
    std::vector<double> x,
    std::vector<double> y,
    std::size_t n);