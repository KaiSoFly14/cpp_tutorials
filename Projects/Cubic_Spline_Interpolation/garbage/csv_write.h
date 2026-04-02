#pragma once
#include <vector>
#include <string>

void writeVectorsToCSV(const std::string& filename, 
                       const std::vector<std::vector<double>>& vectors);