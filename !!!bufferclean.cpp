#include <iostream>
int main(){
    int boundary;
    while (true)
    {
        std::cout << "Enter the boundary for ranging the players: ";
        if (!(std::cin >> boundary))
        {
            std::cin.clear();                                                   // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        else
        {
            break; // Exit the loop if input is valid
        }
    }
}
