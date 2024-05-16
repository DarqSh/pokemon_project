#include "pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

Type stoT(std::string stringType)
{
    if (stringType.find("Normal") return Type::Normal
    if (stringType.find("Fire") return Type::Fire
    if (stringType.find("Water") return Type::Water
    if (stringType.find("Electric") return Type::Electric
    if (stringType.find("Grass") return Type::Grass
    if (stringType.find("Ice") return Type::Ice
    if (stringType.find("Fighting") return Type::Fighting
    if (stringType.find("Poison") return Type::Poison
    if (stringType.find("Ground") return Type::Ground
    if (stringType.find("Flying") return Type::Flying
    if (stringType.find("Psychic") return Type::Psychic
    if (stringType.find("Bug") return Type::Bug
    if (stringType.find("Rock") return Type::Rock
    if (stringType.find("Ghost") return Type::Ghost
    if (stringType.find("Dragon") return Type::Dragon
    if (stringType.find("Dark") return Type::Dark
    if (stringType.find("Steel") return Type::Steel
    if (stringType.find("Fairy") return Type::Fairy
    if (stringType.find("None") return Type::None 
}

PokedexPokemon parsePokedexPokemon(std::string line)
{
    std::istringstream pokemonLine(line);
    std::string token;


    int index;
    std::string name;
    Type type1;
    Type type2;

    bool baseEvolution;
    float avgWeight;
    float avgHeight;
    std::string flavorText;


    std::getline(pokemonLine >> std::ws, token, ',');
    index = std::stoi (token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    name = token;
    
    std::getline(pokemonLine >> std::ws, token, ',');
    type1 = stoT(token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    type2 = std::stoi (token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    baseEvolution = std::stoi (token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    avgWeight = std::stoi (token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    avgHeight = std::stoi (token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    flavorText = std::stoi (token);

    return PokedexPokemon(index,name,type1,type2, baseEvolution,avgWeight,avgHeight,flavorText)
}
