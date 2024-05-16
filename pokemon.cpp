#pragma once
#include "pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

Type stoT(std::string stringType)
{
    if (stringType.find("Normal") != std::string::npos)
        return Type::Normal;
    if (stringType.find("Fire") != std::string::npos)
        return Type::Fire;
    if (stringType.find("Water") != std::string::npos)
        return Type::Water;
    if (stringType.find("Electric") != std::string::npos)
        return Type::Electric;
    if (stringType.find("Grass") != std::string::npos)
        return Type::Grass;
    if (stringType.find("Ice") != std::string::npos)
        return Type::Ice;
    if (stringType.find("Fighting") != std::string::npos)
        return Type::Fighting;
    if (stringType.find("Poison") != std::string::npos)
        return Type::Poison;
    if (stringType.find("Ground") != std::string::npos)
        return Type::Ground;
    if (stringType.find("Flying") != std::string::npos)
        return Type::Flying;
    if (stringType.find("Psychic") != std::string::npos)
        return Type::Psychic;
    if (stringType.find("Bug") != std::string::npos)
        return Type::Bug;
    if (stringType.find("Rock") != std::string::npos)
        return Type::Rock;
    if (stringType.find("Ghost") != std::string::npos)
        return Type::Ghost;
    if (stringType.find("Dragon") != std::string::npos)
        return Type::Dragon;
    if (stringType.find("Dark") != std::string::npos)
        return Type::Dark;
    if (stringType.find("Steel") != std::string::npos)
        return Type::Steel;
    if (stringType.find("Fairy") != std::string::npos)
        return Type::Fairy;
    return Type::None;
}

std::string Ttos(Type type)
{
    if (type == Type::Normal) return "Normal";
    if (type == Type::Fire) return "Fire";
    if (type == Type::Water) return "Water";
    if (type == Type::Electric) return "Electric";
    if (type == Type::Grass) return "Grass";
    if (type == Type::Ice) return "Ice";
    if (type == Type::Fighting) return "Fighting";
    if (type == Type::Poison) return "Poison";
    if (type == Type::Ground) return "Ground";
    if (type == Type::Flying) return "Flying";
    if (type == Type::Psychic) return "Psychic";
    if (type == Type::Bug) return "Bug";
    if (type == Type::Rock) return "Rock";
    if (type == Type::Ghost) return "Ghost";
    if (type == Type::Dragon) return "Dragon";
    if (type == Type::Dark) return  "Dark";
    if (type == Type::Steel) return "Steel";
    if (type == Type::Fairy) return "Fairy";
    return "None" ;
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
    index = std::stoi(token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    name = token;
    
    std::getline(pokemonLine >> std::ws, token, ',');
    std::cout << "Token is " << token << std::endl; 
    type1 = stoT(token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    type2 = stoT(token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    baseEvolution = (token == "true");
    
    std::getline(pokemonLine >> std::ws, token, ',');
    avgWeight = std::stof(token);
    
    std::getline(pokemonLine >> std::ws, token, ',');
    avgHeight = std::stof(token);
    
    std::getline(pokemonLine >> std::ws, token);
    flavorText = token.substr(1, token.size() - 2); // removes quotes
    // std::cout << "This is flavor text" << std::endl;
    // std::cout << flavorText;
    std::cout << index << " " << name << " " << Ttos(type1) << " " << Ttos(type2) << " " << baseEvolution << " " << avgWeight << " " << avgHeight << " " << flavorText;
    return PokedexPokemon(index, name, type1, type2, baseEvolution, avgWeight, avgHeight, flavorText);
}
