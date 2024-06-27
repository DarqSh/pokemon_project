#include "pokemon.hpp"
#include "pokemon.cpp"
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
    std::vector<PokedexPokemon> pokedex;
    std::vector<Attack> baseAttacks;
    std::vector<Attack> specialAttacks;
    std::cout << "This is the main function" << std::endl;
    fillPokedex("pokedex.txt", pokedex);
    fillAttacks("attacks.txt", baseAttacks, specialAttacks);
    #if 0
    for (auto it = pokedex.begin(); it != pokedex.end(); it++)
    {
        std::cout << it->getName() << " " << TypeTtoS(it->getType().first) << TypeTtoS(it->getType().second) << " " << it->getIndex() << " " << it->baseEvoCheck() << std::endl;
    }
    #endif
    #if 0
    std::cout << std::endl << "base attacks:" << std::endl;
    for (auto it = baseAttacks.begin(); it != baseAttacks.end(); it++)
    {
        std::cout << std::setw(15) << std::left <<  it->getName() << std::setw(5) << TypeTtoS(it->getType()) << " " << it->getPower() << std::endl;
    }
    #endif
    #if 0
    std::cout << std::endl << "special attacks:" << std::endl;
    for (auto it = specialAttacks.begin(); it != specialAttacks.end(); it++)
    {
        std::cout << std::setw(15) << std::left <<  it->getName() << std::setw(5) << TypeTtoS(it->getType()) << " " << it->getPower() << std::endl;
    }
    std::cout << "Number of special attacks: " << specialAttacks.size() << std::endl;
    #endif

    
    return 0;
}
