#pragma once

#include <string>
#include <vector>

enum class Type
{
    Normal = 1,
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
    int getIndex() const;
    std::string getName() const;
    std::pair<Type, Type> getType() const; // define the getters/setters
};

class PokedexPokemon : public Pokemon
{
protected:
    bool base_evolution;
    float avg_weight; // in kg
    float avg_height; // in m
    std::string flavor_text;

public:
    PokedexPokemon(int index, std::string name, Type type1, Type type2, bool base_evolution, float avg_weight, float avg_height, std::string flavor_text);
    bool baseEvoCheck() const;
    float getAvgWeight() const;
    float getAvgHeight() const;
    std::string getFlavorText() const;
};

class Attack
{
protected:
    std::string name;
    Type type;
    int power;

public:
    Attack(std::string Name, Type Type, int Power);
    std::string getName() const;
    Type getType() const;
    int getPower() const;
};



class InventoryPokemon : public Pokemon
{
protected:
    // New attributes
    float weight;
    float height;

    int HP;
    int CP; // Combat power
    int defence;

    Attack base_attack;
    Attack special_attack;


public:
    InventoryPokemon(int index, std::string name, Type type1, Type type2, float weight, float height, int HP, int CP, int defence, Attack base_attack, Attack special_attack);
    InventoryPokemon(int index, std::string name, Type type1, Type type2, float weight, float height, int HP, int CP, int defence, std::string base_attack_name, Type base_attack_type, int base_attack_power, std::string special_attack_name, Type special_attack_type, int special_attack_power);
    float getWeight() const;
    float getHeight() const;
    int getHP() const;
    int getCP() const;
    int getDefence() const;
    Attack getBaseAttack() const;
    Attack getSpecialAttack() const;
};

Type TypeStoT(std::string stringType);
std::string TypeTtoS(Type type);

void fillPokedex(const std::string &filename, std::vector<PokedexPokemon>& pokedex);
PokedexPokemon parsePokedexPokemon(const std::string &line);

void fillAttacks(const std::string &filename, std::vector<Attack>& base_attacks, std::vector<Attack>& special_attacks);
std::vector<Attack> parseAttacksLine(std::istringstream& line, Type attack_type);

void fillInventory(const std::string &filename, std::vector<InventoryPokemon>& inventory);
InventoryPokemon parseInventoryPokemon(const std::string &line);
