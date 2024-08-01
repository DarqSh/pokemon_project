#pragma once

#include "pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>

Pokemon::Pokemon(int index, std::string name, Type type1, Type type2) : index(index), name(name), type1(type1), type2(type2) {}
int Pokemon::getIndex() const
{
    return this->index;
}
std::string Pokemon::getName() const
{
    return this->name;
}
std::pair<Type, Type> Pokemon::getType() const
{
    return std::pair<Type, Type>(this->type1, this->type2);
}

PokedexPokemon::PokedexPokemon(int index, std::string name, Type type1, Type type2, bool base_evolution, float avg_weight, float avg_height, std::string flavor_text) : Pokemon(index, name, type1, type2), base_evolution(base_evolution), avg_weight(avg_weight), avg_height(avg_height), flavor_text(flavor_text) {}
bool PokedexPokemon::baseEvoCheck() const
{
    return this->base_evolution;
}
float PokedexPokemon::getAvgWeight() const
{
    return this->avg_weight;
}
float PokedexPokemon::getAvgHeight() const
{
    return this->avg_height;
}
std::string PokedexPokemon::getFlavorText() const
{
    return this->flavor_text;
}

Attack::Attack(std::string Name, Type Type, int Power) : name(Name), type(Type), power(Power) {}
std::string Attack::getName() const
{
    return this->name;
}
Type Attack::getType() const
{
    return this->type;
}
int Attack::getPower() const
{
    return this->power;
}

InventoryPokemon::InventoryPokemon(int index, std::string name, Type type1, Type type2, float weight, float height, int HP, int CP, int defence, Attack base_attack, Attack special_attack)
    : Pokemon(index, name, type1, type2), weight(weight), height(height), HP(HP), CP(CP), defence(defence), base_attack(base_attack), special_attack(special_attack) {}
InventoryPokemon::InventoryPokemon(int index, std::string name, Type type1, Type type2, float weight, float height, int HP, int CP, int defence, std::string base_attack_name, Type base_attack_type, int base_attack_power, std::string special_attack_name, Type special_attack_type, int special_attack_power)
    : Pokemon(index, name, type1, type2), weight(weight), height(height), HP(HP), CP(CP), defence(defence), base_attack(base_attack_name, base_attack_type, base_attack_power), special_attack(special_attack_name, special_attack_type, special_attack_power) {}
float InventoryPokemon::getWeight() const
{
return this->weight;
}
float InventoryPokemon::getHeight() const
{
return this->height;
}
int InventoryPokemon::getHP() const
{
return this->HP;
}
int InventoryPokemon::getCP() const
{
return this->CP;
}
int InventoryPokemon::getDefence() const
{
return this->defence;
}
Attack InventoryPokemon::getBaseAttack() const
{
   return this->base_attack;
}
Attack InventoryPokemon::getSpecialAttack() const
{
   return this->special_attack;
}

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

void fillPokedex(const std::string &filename, std::vector<PokedexPokemon> &pokedex)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        pokedex.push_back(parsePokedexPokemon(line));
    }
}

PokedexPokemon parsePokedexPokemon(const std::string &line)
{
    std::istringstream pokemonLine(line);
    std::string token;

    int index;
    std::string name;
    Type type1;
    Type type2;

    bool base_evolution;
    float avg_weight;
    float avg_height;
    std::string flavor_text;

    std::getline(pokemonLine >> std::ws, token, ',');
    index = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    name = token;

    std::getline(pokemonLine >> std::ws, token, ',');
    type1 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    type2 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    base_evolution = (token == "true");

    std::getline(pokemonLine >> std::ws, token, ',');
    avg_weight = std::stof(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    avg_height = std::stof(token);

    std::getline(pokemonLine >> std::ws, token);
    flavor_text = token.substr(1, token.size() - 2); // removes quotes

#if 0
    // input check
    std::cout << index << " " << name << " " << TypeTtoS(type1) << " " << TypeTtoS(type2) << " " << base_evolution << " " << avg_weight << " " << avg_height << " " << flavor_text << std::endl;
#endif

    return PokedexPokemon(index, name, type1, type2, base_evolution, avg_weight, avg_height, flavor_text);
}

std::vector<Attack> parseAttacksLine(std::istringstream &line, Type attack_type)
{
    std::vector<Attack> attacks;
    std::string attackStr;

    while (std::getline(line, attackStr, ','))
    {
        std::string::size_type start = attackStr.find('(');
        std::string::size_type end = attackStr.find(')');
        std::string attackName = attackStr.substr(0, start - 1);
        int power = std::stoi(attackStr.substr(start + 1, end - start - 1));
        attacks.push_back(Attack(attackName, attack_type, power));
    }
    return attacks;
}
void fillAttacks(const std::string &filename, std::vector<Attack> &base_attacks, std::vector<Attack> &special_attacks)
{
    std::ifstream file(filename);
    std::string Line;
    bool isBaseAttacks; // flag for differentiating between base and charged attacks

    while (std::getline(file, Line))
    {
        if (Line.empty())
            continue; // for deleting the space between base attacks and special attacks
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
        Type type = TypeStoT(stringType); // string to type conversion

        std::vector<Attack> attacks = parseAttacksLine(line, type);
        if (isBaseAttacks)
            base_attacks.insert(base_attacks.end(), attacks.begin(), attacks.end()); // one of insert() functions' overloads
        else
            special_attacks.insert(special_attacks.end(), attacks.begin(), attacks.end());
    }
}

void fillInventory(const std::string &filename, std::vector<InventoryPokemon> &inventory)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        inventory.push_back(parseInventoryPokemon(line));
    }
}
InventoryPokemon parseInventoryPokemon(const std::string &line)
{
    std::istringstream pokemonLine(line);
    std::string token;

    int index;
    std::string name;
    Type type1;
    Type type2;

    float weight;
    float height;

    int HP;
    int CP;
    int defence;

    std::string base_attack_name;
    Type base_attack_type;
    int base_attack_power;
    std::string special_attack_name;
    Type special_attack_type;
    int special_attack_power;

    std::getline(pokemonLine >> std::ws, token, ',');
    index = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    name = token;

    std::getline(pokemonLine >> std::ws, token, ',');
    type1 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    type2 = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    weight = std::stof(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    height = std::stof(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    HP = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    CP = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    defence = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    base_attack_name = token;

    std::getline(pokemonLine >> std::ws, token, ',');
    base_attack_type = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    base_attack_power = std::stoi(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    special_attack_name = token;

    std::getline(pokemonLine >> std::ws, token, ',');
    special_attack_type = TypeStoT(token);

    std::getline(pokemonLine >> std::ws, token, ',');
    special_attack_power = std::stoi(token);

#if 0
    // input check
    std::cout << index << " " << name << " " << TypeTtoS(type1) << " " << TypeTtoS(type2) << " " << weight << " " << height << " " << base_attack_name << " " << TypeTtoS(base_attack_type) << base_attack_power << special_attack_name << " " << TypeTtoS(special_attack_type) << special_attack_power << std::endl;
#endif

    return InventoryPokemon(index, name, type1, type2, weight, height, HP, CP, defence, base_attack_name, base_attack_type, base_attack_power, special_attack_name, special_attack_type, special_attack_power);
}
