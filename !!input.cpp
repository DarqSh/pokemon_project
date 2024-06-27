#include <iostream>
#include <vector>
#include <string>

int main() {
    // Define a vector of strings
    std::vector<std::string> strings = {"apple", "banana", "orange", "grape", "pear"};

    // Get input string from user
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    // Iterate through the vector and find strings containing the input
    std::cout << "Strings containing \"" << input << "\":" << std::endl;
    for (const std::string& str : strings) {
        if (str.find(input) != std::string::npos) {
            std::cout << str << std::endl;
        }
    }

    return 0;
}
