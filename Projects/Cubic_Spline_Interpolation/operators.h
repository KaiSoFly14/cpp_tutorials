#pragma once
#include <vector>

std::vector<double>
operator+(const std::vector<double>& a,
          const std::vector<double>& b);

std::vector<double>
operator+(const double& a,
          const std::vector<double>& b);

std::vector<double>
operator+(const std::vector<double>& a,
          const double& b);

std::vector<double>
operator-(const std::vector<double>& a,
          const std::vector<double>& b);

std::vector<double>
operator-(const double& a,
          const std::vector<double>& b);

std::vector<double>
operator-(const std::vector<double>& a,
          const double& b);

std::vector<double>
operator*(const std::vector<double>& a,
          const std::vector<double>& b);

std::vector<double> 
operator*(const double& a, 
          const std::vector<double>& b);

std::vector<double> 
operator*(const std::vector<double>& a,
          const double& b);

std::vector<double>
operator/(const std::vector<double>& a,
          const std::vector<double>& b);

std::vector<double> 
operator/(const double& a, 
          const std::vector<double>& b);

std::vector<double> 
operator/(const std::vector<double>& a,
          const double& b);