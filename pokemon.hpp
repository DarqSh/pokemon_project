#pragma once

#include <string>
#include <vector>

enum class Type
{
    Normal,
    Fire,
    Water,
    Electric,
    Grass,
    Ice,
    Fighting,
    Poison,
    Ground,
    Flying,
    Psychic,
    Bug,
    Rock,
    Ghost,
    Dragon,
    Dark,
    Steel,
    Fairy,
    None // For Pokémon with only one type
};

class Pokemon
{
protected:
    int index;
    std::string name;
    Type type1;
    Type type2;

public:
    Pokemon(int index, std::string name, Type type1, Type type2);
    int getIndex();
    std::string getName();
    std::pair<Type, Type> getType(); // define the getters/setters
};

class PokedexPokemon : public Pokemon
{
protected:
    bool baseEvolution;
    float avgWeight; // in kg
    float avgHeight; // in m
    std::string flavorText;

public:
    PokedexPokemon(int index, std::string name, Type type1, Type type2, bool baseEvolution, float avgWeight, float avgHeight, std::string flavorText);
    bool baseEvoCheck();
};

class Attack
{
protected:
    std::string name;
    Type type;
    int power;

public:
    Attack(std::string Name, Type Type, int Power);
    std::string getName();
    Type getType();
    int getPower();
};



class InventoryPokemon : public Pokemon
{
protected:
    // New attributes
    double weight;
    double height;

    int baseHP;
    int baseCP; // Combat power
    int baseDefense;

    std::string baseAttack;
    int baseAttackPower;
    std::string specialAttack;
    int specialAttackPower;

public:
    InventoryPokemon(int index, std::string name, Type type1, Type type2, double weight, double height, int baseHP, int baseCP, int baseDefense, std::string baseAttack, int baseAttackPower, std::string specialAttack, int specialAttackPower);
};

Type TypeStoT(std::string stringType);
std::string TypeTtoS(Type type);

void fillPokedex(const std::string &filename, std::vector<PokedexPokemon>& pokedex);
PokedexPokemon parsePokedexPokemon(const std::string &line);

void fillAttacks(const std::string &filename, std::vector<Attack>& baseAttacks, std::vector<Attack>& specialAttacks);
std::vector<Attack> parseAttacksLine(std::istringstream& line, Type attackType);
