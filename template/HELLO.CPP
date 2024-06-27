#include <iostream>

int main() {
    // Change text color to red
    std::cout << "\033[1;31mHello, ";
    // Change text color to green
    std::cout << "\033[1;34mworld!";
    // Reset text color
    std::cout << "\033[0m" << std::endl;

    return 0;
}
