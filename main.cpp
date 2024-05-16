#include "pokemon.hpp"
#include "pokemon.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

int main()
{
    std::fstream File;
    std::string string;
    File.open("pokedex.txt", std::ios::in);
    (File.is_open()) ? (std::cout << "File is opened successfully" << std::endl) : (std::cout << "File is not opened" << std::endl);
    
    while(std::getline (File, string)){
    PokedexPokemon pokemon = parsePokedexPokemon(string);
    }

    File.close();
    return 0;
}
