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
    Pokemon(int index, std::string name, Type type1, Type type2) : index(index), name(name), type1(type1), type2(type2){}
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
    PokedexPokemon(int index, std::string name, Type type1, Type type2, bool baseEvolution, float avgWeight, float avgHeight, std::string flavorText) : Pokemon(index, name, type1, type2), baseEvolution(baseEvolution), avgWeight(avgWeight), avgHeight(avgHeight), flavorText(flavorText){}
    bool baseEvoCheck();
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
    InventoryPokemon(int index, std::string name, Type type1, Type type2, double weight, double height, int baseHP, int baseCP, int baseDefense, std::string baseAttack, int baseAttackPower, std::string specialAttack, int specialAttackPower) 
    : Pokemon(index, name, type1, type2), weight (weight), height (height), baseHP (baseHP), baseCP (baseCP), baseDefense (baseDefense), baseAttack (baseAttack), baseAttackPower (baseAttackPower), specialAttack (specialAttack), specialAttackPower (specialAttackPower){}
};

Type TypestoT(std::string stringType);
std::string TypeTtos(Type type);

PokedexPokemon parsePokedexPokemon(const std::string& line);
