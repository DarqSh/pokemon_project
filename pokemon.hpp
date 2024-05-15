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
public:
    int index;
    std::string name;
    Type type1;
    Type type2;
    bool baseEvolution;
    float avgWeight; // in kg
    float avgHeight; // in m

    // New attributes
    int baseHP;
    int baseAttack;
    int baseDefense;
    int baseSpecialAttack;
    int baseSpecialDefense;
    int baseSpeed;
    std::vector<std::string> abilities;
    std::string evolvesTo;
    int evolveLevel;
    std::string evolutionMethod;
    std::vector<std::string> eggGroups;
    int catchRate;
    float maleRatio;
    float femaleRatio;
    int baseExperience;
    std::string growthRate;
    std::vector<std::string> heldItems;
    std::string flavorText;
};



#if 0
Pokemon kantoPokemon[] = {
    {1, "Bulbasaur", Type::Grass, Type::Poison, 0, 6.9, 0.7},
    {2, "Ivysaur", Type::Grass, Type::Poison, "AAAAAAAAAA", 13.0, 1.0},
    {3, "Venusaur", Type::Grass, Type::Poison, 2, 100.0, 2.0},
    {4, "Charmander", Type::Fire, Type::None, 0, 8.5, 0.6},
    {5, "Charmeleon", Type::Fire, Type::None, "AAAAAAAAAA", 19.0, 1.1},
    {6, "Charizard", Type::Fire, Type::Flying, 2, 90.5, 1.7},
    {7, "Squirtle", Type::Water, Type::None, 0, 9.0, 0.5},
    {8, "Wartortle", Type::Water, Type::None, "AAAAAAAAAA", 22.5, 1.0},
    {9, "Blastoise", Type::Water, Type::None, 2, 85.5, 1.6},
    {10, "Caterpie", Type::Bug, Type::None, 0, 2.9, 0.3},
    {11, "Metapod", Type::Bug, Type::None, "AAAAAAAAAA", 9.9, 0.7},
    {12, "Butterfree", Type::Bug, Type::Flying, 2, 32.0, 1.1},
    {13, "Weedle", Type::Bug, Type::Poison, 0, 3.2, 0.3},
    {14, "Kakuna", Type::Bug, Type::Poison, "AAAAAAAAAA", 10.0, 0.6},
    {15, "Beedrill", Type::Bug, Type::Poison, 2, 29.5, 1.0},
    {16, "Pidgey", Type::Normal, Type::Flying, 0, 1.8, 0.3},
    {17, "Pidgeotto", Type::Normal, Type::Flying, "AAAAAAAAAA", 30.0, 1.1},
    {18, "Pidgeot", Type::Normal, Type::Flying, 2, 39.5, 1.5},
    {19, "Rattata", Type::Normal, Type::None, 0, 3.5, 0.3},
    {20, "Raticate", Type::Normal, Type::None, "AAAAAAAAAA", 18.5, 0.7},
    {21, "Spearow", Type::Normal, Type::Flying, 0, 2.0, 0.3},
    {22, "Fearow", Type::Normal, Type::Flying, "AAAAAAAAAA", 38.0, 1.2},
    {23, "Ekans", Type::Poison, Type::None, 0, 6.9, 2.0},
    {24, "Arbok", Type::Poison, Type::None, "AAAAAAAAAA", 65.0, 3.5},
    {25, "Pikachu", Type::Electric, Type::None, 0, 6.0, 0.4},
    {26, "Raichu", Type::Electric, Type::None, "AAAAAAAAAA", 30.0, 0.8},
    {27, "Sandshrew", Type::Ground, Type::None, 0, 12.0, 0.6},
    {28, "Sandslash", Type::Ground, Type::None, "AAAAAAAAAA", 29.5, 1.0},
    {29, "Nidoran♀", Type::Poison, Type::None, 0, 7.0, 0.4},
    {30, "Nidorina", Type::Poison, Type::None, "AAAAAAAAAA", 20.0, 0.8},
    {31, "Nidoqueen", Type::Poison, Type::Ground, 2, 60.0, 1.3},
    {32, "Nidoran♂", Type::Poison, Type::None, 0, 9.0, 0.5},
    {33, "Nidorino", Type::Poison, Type::None, "AAAAAAAAAA", 19.5, 0.9},
    {34, "Nidoking", Type::Poison, Type::Ground, 2, 62.0, 1.4},
    {35, "Clefairy", Type::Fairy, Type::None, 0, 7.5, 0.6},
    {36, "Clefable", Type::Fairy, Type::None, "AAAAAAAAAA", 40.0, 1.3},
    {37, "Vulpix", Type::Fire, Type::None, 0, 9.9, 0.6},
    {38, "Ninetales", Type::Fire, Type::None, "AAAAAAAAAA", 19.9, 1.1},
    {39, "Jigglypuff", Type::Normal, Type::Fairy, 0, 5.5, 0.5},
    {40, "Wigglytuff", Type::Normal, Type::Fairy, "AAAAAAAAAA", 12.0, 1.0},
    {41, "Zubat", Type::Poison, Type::Flying, 0, 7.5, 0.8},
    {42, "Golbat", Type::Poison, Type::Flying, "AAAAAAAAAA", 55.0, 1.6},
    {43, "Oddish", Type::Grass, Type::Poison, 0, 5.4, 0.5},
    {44, "Gloom", Type::Grass, Type::Poison, "AAAAAAAAAA", 8.6, 0.8},
    {45, "Vileplume", Type::Grass, Type::Poison, 2, 18.6, 1.2},
    {46, "Paras", Type::Bug, Type::Grass, 0, 5.4, 0.3},
    {47, "Parasect", Type::Bug, Type::Grass, "AAAAAAAAAA", 29.5, 1.0},
    {48, "Venonat", Type::Bug, Type::Poison, 0, 30.0, 1.0},
    {49, "Venomoth", Type::Bug, Type::Poison, "AAAAAAAAAA", 12.5, 1.5},
    {50, "Diglett", Type::Ground, Type::None, 0, 0.8, 0.2},
    {51, "Dugtrio", Type::Ground, Type::None, "AAAAAAAAAA", 33.3, 0.7},
    {52, "Meowth", Type::Normal, Type::None, 0, 4.2, 0.4},
    {53, "Persian", Type::Normal, Type::None, "AAAAAAAAAA", 32.0, 1.0},
    {54, "Psyduck", Type::Water, Type::None, 0, 19.6, 0.8},
    {55, "Golduck", Type::Water, Type::None, "AAAAAAAAAA", 76.6, 1.7},
    {56, "Mankey", Type::Fighting, Type::None, 0, 28.0, 0.5},
    {57, "Primeape", Type::Fighting, Type::None, "AAAAAAAAAA", 32.0, 1.0},
    {58, "Growlithe", Type::Fire, Type::None, 0, 19.0, 0.7},
    {59, "Arcanine", Type::Fire, Type::None, "AAAAAAAAAA", 155.0, 1.9},
    {60, "Poliwag", Type::Water, Type::None, 0, 12.4, 0.6},
    {61, "Poliwhirl", Type::Water, Type::None, "AAAAAAAAAA", 20.0, 1.0},
    {62, "Poliwrath", Type::Water, Type::Fighting, 2, 54.0, 1.3},
    {63, "Abra", Type::Psychic, Type::None, 0, 19.5, 0.9},
    {64, "Kadabra", Type::Psychic, Type::None, "AAAAAAAAAA", 56.5, 1.3},
    {65, "Alakazam", Type::Psychic, Type::None, 2, 48.0, 1.5},
    {66, "Machop", Type::Fighting, Type::None, 0, 19.5, 0.8},
    {67, "Machoke", Type::Fighting, Type::None, "AAAAAAAAAA", 70.5, 1.5},
    {68, "Machamp", Type::Fighting, Type::None, 2, 130.0, 1.6},
    {69, "Bellsprout", Type::Grass, Type::Poison, 0, 4.0, 0.7},
    {70, "Weepinbell", Type::Grass, Type::Poison, "AAAAAAAAAA", 6.4, 1.0},
    {71, "Victreebel", Type::Grass, Type::Poison, 2, 15.5, 1.7},
    {72, "Tentacool", Type::Water, Type::Poison, 0, 45.5, 0.9},
    {73, "Tentacruel", Type::Water, Type::Poison, "AAAAAAAAAA", 55.0, 1.6},
    {74, "Geodude", Type::Rock, Type::Ground, 0, 20.0, 0.4},
    {75, "Graveler", Type::Rock, Type::Ground, "AAAAAAAAAA", 105.0, 1.0},
    {76, "Golem", Type::Rock, Type::Ground, 2, 300.0, 1.4},
    {77, "Ponyta", Type::Fire, Type::None, 0, 30.0, 1.0},
    {78, "Rapidash", Type::Fire, Type::None, "AAAAAAAAAA", 95.0, 1.7},
    {79, "Slowpoke", Type::Water, Type::Psychic, 0, 36.0, 1.2},
    {80, "Slowbro", Type::Water, Type::Psychic, "AAAAAAAAAA", 78.5, 1.6},
    {81, "Magnemite", Type::Electric, Type::Steel, 0, 6.0, 0.3},
    {82, "Magneton", Type::Electric, Type::Steel, "AAAAAAAAAA", 60.0, 1.0},
    {83, "Farfetch'd", Type::Normal, Type::Flying, 0, 15.0, 0.8},
    {84, "Doduo", Type::Normal, Type::Flying, 0, 39.2, 1.4},
    {85, "Dodrio", Type::Normal, Type::Flying, "AAAAAAAAAA", 85.2, 1.8},
    {86, "Seel", Type::Water, Type::None, 0, 90.0, 1.1},
    {87, "Dewgong", Type::Water, Type::Ice, "AAAAAAAAAA", 120.0, 1.7},
    {88, "Grimer", Type::Poison, Type::None, 0, 30.0, 0.9},
    {89, "Muk", Type::Poison, Type::None, "AAAAAAAAAA", 30.0, 1.2},
    {90, "Shellder", Type::Water, Type::None, 0, 4.0, 0.3},
    {91, "Cloyster", Type::Water, Type::Ice, "AAAAAAAAAA", 132.5, 1.5},
    {92, "Gastly", Type::Ghost, Type::Poison, 0, 0.1, 1.3},
    {93, "Haunter", Type::Ghost, Type::Poison, "AAAAAAAAAA", 0.1, 1.6},
    {94, "Gengar", Type::Ghost, Type::Poison, 2, 40.5, 1.5},
    {95, "Onix", Type::Rock, Type::Ground, 0, 210.0, 8.8},
    {96, "Drowzee", Type::Psychic, Type::None, 0, 32.4, 1.0},
    {97, "Hypno", Type::Psychic, Type::None, "AAAAAAAAAA", 75.6, 1.6},
    {98, "Krabby", Type::Water, Type::None, 0, 6.5, 0.4},
    {99, "Kingler", Type::Water, Type::None, "AAAAAAAAAA", 60.0, 1.3},
    {100, "Voltorb", Type::Electric, Type::None, 0, 10.4, 0.5},
    {101, "Electrode", Type::Electric, Type::None, "AAAAAAAAAA", 66.6, 1.2},
    {102, "Exeggcute", Type::Grass, Type::Psychic, 0, 2.5, 0.4},
    {103, "Exeggutor", Type::Grass, Type::Psychic, "AAAAAAAAAA", 120.0, 2.0},
    {104, "Cubone", Type::Ground, Type::None, 0, 6.5, 0.4},
    {105, "Marowak", Type::Ground, Type::None, "AAAAAAAAAA", 45.0, 1.0},
    {106, "Hitmonlee", Type::Fighting, Type::None, 0, 49.8, 1.5},
    {107, "Hitmonchan", Type::Fighting, Type::None, 0, 50.2, 1.4},
    {108, "Lickitung", Type::Normal, Type::None, 0, 65.5, 1.2},
    {109, "Koffing", Type::Poison, Type::None, 0, 1.0, 0.6},
    {110, "Weezing", Type::Poison, Type::None, "AAAAAAAAAA", 9.5, 1.2},
    {111, "Rhyhorn", Type::Ground, Type::Rock, 0, 115.0, 1.0},
    {112, "Rhydon", Type::Ground, Type::Rock, "AAAAAAAAAA", 120.0, 1.9},
    {113, "Chansey", Type::Normal, Type::None, 0, 34.6, 1.1},
    {114, "Tangela", Type::Grass, Type::None, 0, 35.0, 1.0},
    {115, "Kangaskhan", Type::Normal, Type::None, 0, 80.0, 2.2},
    {116, "Horsea", Type::Water, Type::None, 0, 8.0, 0.4},
    {117, "Seadra", Type::Water, Type::None, "AAAAAAAAAA", 25.0, 1.2},
    {118, "Goldeen", Type::Water, Type::None, 0, 15.0, 0.6},
    {119, "Seaking", Type::Water, Type::None, "AAAAAAAAAA", 39.0, 1.3},
    {120, "Staryu", Type::Water, Type::None, 0, 34.5, 0.8},
    {121, "Starmie", Type::Water, Type::Psychic, "AAAAAAAAAA", 80.0, 1.1},
    {122, "Mr. Mime", Type::Psychic, Type::Fairy, 0, 54.5, 1.3},
    {123, "Scyther", Type::Bug, Type::Flying, 0, 56.0, 1.5},
    {124, "Jynx", Type::Ice, Type::Psychic, 0, 40.6, 1.4},
    {125, "Electabuzz", Type::Electric, Type::None, 0, 30.0, 1.1},
    {126, "Magmar", Type::Fire, Type::None, 0, 44.5, 1.3},
    {127, "Pinsir", Type::Bug, Type::None, 0, 55.0, 1.5},
    {128, "Tauros", Type::Normal, Type::None, 0, 88.4, 1.4},
    {129, "Magikarp", Type::Water, Type::None, 0, 10.0, 0.9},
    {130, "Gyarados", Type::Water, Type::Flying, "AAAAAAAAAA", 235.0, 6.5},
    {131, "Lapras", Type::Water, Type::Ice, 0, 220.0, 2.5},
    {132, "Ditto", Type::Normal, Type::None, 0, 4.0, 0.3},
    {133, "Eevee", Type::Normal, Type::None, 0, 6.5, 0.3},
    {134, "Vaporeon", Type::Water, Type::None, "AAAAAAAAAA", 29.0, 1.0},
    {135, "Jolteon", Type::Electric, Type::None, "AAAAAAAAAA", 24.5, 0.8},
    {136, "Flareon", Type::Fire, Type::None, "AAAAAAAAAA", 25.0, 0.9},
    {137, "Porygon", Type::Normal, Type::None, 0, 36.5, 0.8},
    {138, "Omanyte", Type::Rock, Type::Water, 0, 7.5, 0.4},
    {139, "Omastar", Type::Rock, Type::Water, "AAAAAAAAAA", 35.0, 1.0},
    {140, "Kabuto", Type::Rock, Type::Water, 0, 11.5, 0.5},
    {141, "Kabutops", Type::Rock, Type::Water, "AAAAAAAAAA", 40.5, 1.3},
    {142, "Aerodactyl", Type::Rock, Type::Flying, 0, 59.0, 1.8},
    {143, "Snorlax", Type::Normal, Type::None, 0, 460.0, 2.1},
    {144, "Articuno", Type::Ice, Type::Flying, "AAAAAAAAAA", 55.4, 1.7},
    {145, "Zapdos", Type::Electric, Type::Flying, "AAAAAAAAAA", 52.6, 1.6},
    {146, "Moltres", Type::Fire, Type::Flying, "AAAAAAAAAA", 60.0, 2.0},
    {147, "Dratini", Type::Dragon, Type::None, 0, 3.3, 1.8},
    {148, "Dragonair", Type::Dragon, Type::None, "AAAAAAAAAA", 16.5, 4.0},
    {149, "Dragonite", Type::Dragon, Type::Flying, 2, 210.0, 2.2},
    {150, "Mewtwo", Type::Psychic, Type::None, "AAAAAAAAAA", 122.0, 2.0},
    {151, "Mew", Type::Psychic, Type::None, 2, 4.0, 0.4}
#endif
