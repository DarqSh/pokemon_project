#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function to search for a substring in a vector of strings
int findSubstring(const std::vector<std::string>& vec, const std::string& substr) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i].find(substr) != std::string::npos) {
            return static_cast<int>(i); // Return the index of the string containing the substring
        }
    }
    return -1; // Return -1 if the substring is not found
}

int main() {
    std::vector<std::string> strings = {"apple", "banana", "orange", "grape", "kiwi"};

    std::string input;
    std::cout << "Enter 'find:string' to search for a substring: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string command, searchString;
    std::getline(iss, command, ':'); // Read the command part before the colon
    std::getline(iss, searchString); // Read the search string part after the colon

    std::cout << "Command is" << command <<std::endl;
    std::cout << "searchString  is" << searchString <<  std::endl;

    return 0;
}
