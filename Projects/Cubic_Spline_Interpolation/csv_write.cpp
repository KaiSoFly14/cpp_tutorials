#include <fstream>
#include <vector>
#include <string>

void writeVectorsToCSV(const std::string& filename, 
                       const std::vector<std::vector<double>>& vectors) {
    
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    // Loop through each vector
    for (const auto& vec : vectors) {
        // Write elements of this vector
        for (std::size_t i = 0; i < vec.size(); i++) {
            file << vec[i];
            if (i < vec.size() - 1) {
                file << ",";  // Comma between values
            }
        }
        file << "\n";  // New line after each vector
    }
    
    file.close();
}