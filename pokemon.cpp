#pragma once

#include "pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>

Pokemon::Pokemon(int index, std::string name, Type type1, Type type2) : index(index), name(name), type1(type1), type2(type2) {}
int Pokemon::getIndex()
{
    return this->index;
}
std::string Pokemon::getName()
{
    return this->name;
}
std::pair<Type, Type> Pokemon::getType()
{
    return std::pair<Type, Type>(this->type1, this->type2);
}

PokedexPokemon::PokedexPokemon(int index, std::string name, Type type1, Type type2, bool baseEvolution, float avgWeight, float avgHeight, std::string flavorText) : Pokemon(index, name, type1, type2), baseEvolution(baseEvolution), avgWeight(avgWeight), avgHeight(avgHeight), flavorText(flavorText) {}
bool PokedexPokemon::baseEvoCheck()
{
    return this->baseEvolution;
}

Attack::Attack(std::string Name, Type Type, int Power) : name(Name), type(Type), power(Power) {}
std::string Attack::getName()
{
    return this->name;
}
Type Attack::getType()
{
    return this->type;
}
int Attack::getPower()
{
    return this->power;
}

InventoryPokemon::InventoryPokemon(int index, std::string name, Type type1, Type type2, double weight, double height, int baseHP, int baseCP, int baseDefense, std::string baseAttack, int baseAttackPower, std::string specialAttack, int specialAttackPower)
    : Pokemon(index, name, type1, type2), weight(weight), height(height), baseHP(baseHP), baseCP(baseCP), baseDefense(baseDefense), baseAttack(baseAttack), baseAttackPower(baseAttackPower), specialAttack(specialAttack), specialAttackPower(specialAttackPower) {}

Type TypeStoT(std::string stringType)
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

std::string TypeTtoS(Type type)
{
    if (type == Type::Normal)
        return "Normal";
    if (type == Type::Fire)
        return "Fire";
    if (type == Type::Water)
        return "Water";
    if (type == Type::Electric)
        return "Electric";
    if (type == Type::Grass)
        return "Grass";
    if (type == Type::Ice)
        return "Ice";
    if (type == Type::Fighting)
        return "Fighting";
    if (type == Type::Poison)
        return "Poison";
    if (type == Type::Ground)
        return "Ground";
    if (type == Type::Flying)
        return "Flying";
    if (type == Type::Psychic)
        return "Psychic";
    if (type == Type::Bug)
        return "Bug";
    if (type == Type::Rock)
        return "Rock";
    if (type == Type::Ghost)
        return "Ghost";
    if (type == Type::Dragon)
        return "Dragon";
    if (type == Type::Dark)
        return "Dark";
    if (type == Type::Steel)
        return "Steel";
    if (type == Type::Fairy)
        return "Fairy";
    return "None";
}

PokedexPokemon parsePokedexPokemon(const std::string &line)
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
    type1 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    type2 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    baseEvolution = (token == "true");

    std::getline(pokemonLine >> std::ws, token, ',');
    avgWeight = std::stof(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    avgHeight = std::stof(token);

    std::getline(pokemonLine >> std::ws, token);
    flavorText = token.substr(1, token.size() - 2); // removes quotes

#if 1
    // input check
    std::cout << index << " " << name << " " << TypeTtoS(type1) << " " << TypeTtoS(type2) << " " << baseEvolution << " " << avgWeight << " " << avgHeight << " " << flavorText << std::endl;
#endif

    return PokedexPokemon(index, name, type1, type2, baseEvolution, avgWeight, avgHeight, flavorText);
}

std::vector<Attack> parseAttacksLine(std::istringstream& line, Type attackType)
{
    std::vector<Attack> attacks;
    std::string attackStr;

    while (std::getline(line, attackStr, ','))
    {
        std::string::size_type start = attackStr.find('(');
        std::string::size_type end = attackStr.find(')');
        std::string attackName = attackStr.substr(0, start - 1);
        int power = std::stoi(attackStr.substr(start + 1, end - start - 1));
        attacks.push_back(Attack(attackName, attackType, power));
    }
    return attacks;
}

void parseAttacksFile(const std::string &filename, std::vector<Attack>& baseAttacks, std::vector<Attack>& specialAttacks )
{
    std::ifstream file(filename);
    std::string Line;
    bool isBaseAttacks; // flag for differentiating between base and charged attacks

    while (std::getline(file, Line))
    {
        if (Line.empty())
            continue; //for deleting the space between base attacks and special attacks
        if (Line == "Base Attacks (Fast Moves)")
        {
            isBaseAttacks = true;
            continue;
        }
        else if (Line == "Special Attacks (Charge Moves)")
        {
            isBaseAttacks = false;
            continue;
        }

    std::istringstream line(Line);
    std::string stringType;

    std::getline(line, stringType, ':');
    Type type = TypeStoT(stringType); //string to type conversion

    std::vector<Attack> attacks = parseAttacksLine(line, type);
    if(isBaseAttacks) baseAttacks.insert(baseAttacks.end(), attacks.begin(), attacks.end()); // one of insert() functions' overloads
    else specialAttacks.insert(specialAttacks.end(), attacks.begin(), attacks.end());
    }
}
