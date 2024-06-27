#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> lines;
    std::string line;

    std::cout << "Enter multiple lines of input. Enter 'quit' to finish:\n";

    // Read input line by line until "quit" is entered
    while (std::getline(std::cin, line)) {
        if (line == "quit") {
            break;  // Exit loop if "quit" is entered
        }
        lines.push_back(line);  // Store the line in the vector
    }

    // Display the lines entered by the user
    std::cout << "\nYou entered:\n";
    for (auto& l : lines) {
        std::cout << l << std::endl;
    }

    return 0;
}
