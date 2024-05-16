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
    Pokemon(int index, std::string name, Type type1, Type type2) : index(index), name(name), type1(type1), type2(type2)
    {
    }
};

class PokedexPokemon : public Pokemon
{
protected:
    bool baseEvolution;
    float avgWeight; // in kg
    float avgHeight; // in m
    std::string flavorText;

public:
    PokedexPokemon(int index, std::string name, Type type1, Type type2, bool baseEvolution, float avgWeight, float avgHeight, std::string flavorText) : Pokemon(index, name, type1, type2), baseEvolution(baseEvolution), avgWeight(avgWeight), avgHeight(avgHeight), flavorText(flavorText)
    {
    }
};

class InventoryPokemon : public Pokemon
{
public:
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
};


Type stoT(std::string stringType);
std::string Ttos(Type type);

PokedexPokemon parsePokedexPokemon(std::string line);





