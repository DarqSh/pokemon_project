#include <iostream>
#include <vector>
#include <algorithm>

bool compareNames(const std::string& a, const std::string& b) {
    return a < b; // Compare strings lexicographically
}   

int main() {
    std::vector<std::string> names = {"John", "Alice", "Bob", "Charlie", "Alice"};

    // Sort the vector using the compareNames function
    std::sort(names.begin(), names.end(), compareNames);

    // Print the sorted vector
    for(const auto& name : names) {
        std::cout << name << std::endl;
    }

    return 0;
}
