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






#if 0
std::vector<PokedexPokemon> kantoPokemon = {
        PokedexPokemon(1, "Bulbasaur", Type::Grass, Type::Poison, true, 6.9f, 0.7f, "A strange seed was planted on its back at birth. The plant sprouts and grows with this Pokémon."),
        PokedexPokemon(2, "Ivysaur", Type::Grass, Type::Poison, false, 13.0f, 1.0f, "When the bulb on its back grows large, it appears to lose the ability to stand on its hind legs."),
        PokedexPokemon(3, "Venusaur", Type::Grass, Type::Poison, false, 100.0f, 2.0f, "The plant blooms when it is absorbing solar energy. It stays on the move to seek sunlight."),
        PokedexPokemon(4, "Charmander", Type::Fire, Type::None, true, 8.5f, 0.6f, "Obviously prefers hot places. When it rains, steam is said to spout from the tip of its tail."),
        PokedexPokemon(5, "Charmeleon", Type::Fire, Type::None, false, 19.0f, 1.1f, "When it swings its burning tail, it elevates the temperature to unbearably high levels."),
        PokedexPokemon(6, "Charizard", Type::Fire, Type::Flying, false, 90.5f, 1.7f, "Spits fire that is hot enough to melt boulders. Known to cause forest fires unintentionally."),
        PokedexPokemon(7, "Squirtle", Type::Water, Type::None, true, 9.0f, 0.5f, "After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth."),
        PokedexPokemon(8, "Wartortle", Type::Water, Type::None, false, 22.5f, 1.0f, "Often hides in water to stalk unwary prey. For swimming fast, it moves its ears to maintain balance."),
        PokedexPokemon(9, "Blastoise", Type::Water, Type::None, false, 85.5f, 1.6f, "A brutal Pokémon with pressurized water jets on its shell. They are used for high-speed tackles."),
        PokedexPokemon(10, "Caterpie", Type::Bug, Type::None, true, 2.9f, 0.3f, "Its short feet are tipped with suction pads that enable it to tirelessly climb slopes and walls."),
        PokedexPokemon(11, "Metapod", Type::Bug, Type::None, false, 9.9f, 0.7f, "This Pokémon is vulnerable to attack while its shell is soft, exposing its weak and tender body."),
        PokedexPokemon(12, "Butterfree", Type::Bug, Type::Flying, false, 32.0f, 1.1f, "In battle, it flaps its wings at great speed to release highly toxic dust into the air."),
        PokedexPokemon(13, "Weedle", Type::Bug, Type::Poison, true, 3.2f, 0.3f, "Often found in forests, eating leaves. It has a sharp venomous stinger on its head."),
        PokedexPokemon(14, "Kakuna", Type::Bug, Type::Poison, false, 10.0f, 0.6f, "Almost incapable of moving, this Pokémon can only harden its shell to protect itself from predators."),
        PokedexPokemon(15, "Beedrill", Type::Bug, Type::Poison, false, 29.5f, 1.0f, "Flies at high speed and attacks using its large venomous stingers on its forelegs and tail."),
        PokedexPokemon(16, "Pidgey", Type::Normal, Type::Flying, true, 1.8f, 0.3f, "A common sight in forests and woods. It flaps its wings at ground level to kick up blinding sand."),
        PokedexPokemon(17, "Pidgeotto", Type::Normal, Type::Flying, false, 30.0f, 1.1f, "Very protective of its sprawling territorial area, this Pokémon will fiercely peck at any intruder."),
        PokedexPokemon(18, "Pidgeot", Type::Normal, Type::Flying, false, 39.5f, 1.5f, "When hunting, it skims the surface of water at high speed to pick off unwary prey such as Magikarp."),
        PokedexPokemon(19, "Rattata", Type::Normal, Type::None, true, 3.5f, 0.3f, "Bites anything when it attacks. Small and very quick, it is a common sight in many places."),
        PokedexPokemon(20, "Raticate", Type::Normal, Type::None, false, 18.5f, 0.7f, "Its hind feet are webbed. They act as flippers, so it can swim in rivers and hunt for prey."),
        PokedexPokemon(21, "Spearow", Type::Normal, Type::Flying, true, 2.0f, 0.3f, "Inept at flying high. However, it can fly around very fast to protect its territory."),
        PokedexPokemon(22, "Fearow", Type::Normal, Type::Flying, false, 38.0f, 1.2f, "With its huge and magnificent wings, it can keep aloft without ever having to land for rest."),
        PokedexPokemon(23, "Ekans", Type::Poison, Type::None, true, 6.9f, 2.0f, "Moves silently and stealthily. Eats the eggs of birds, such as Pidgey and Spearow, whole."),
        PokedexPokemon(24, "Arbok", Type::Poison, Type::None, false, 65.0f, 3.5f, "The frightening patterns on its belly have been studied. Six variations have been confirmed."),
        PokedexPokemon(25, "Pikachu", Type::Electric, Type::None, true, 6.0f, 0.4f, "When several of these Pokémon gather, their electricity could build and cause lightning storms."),
        PokedexPokemon(26, "Raichu", Type::Electric, Type::None, false, 30.0f, 0.8f, "Its long tail serves as a ground to protect itself from its own high-voltage power."),
        PokedexPokemon(27, "Sandshrew", Type::Ground, Type::None, true, 12.0f, 0.6f, "Burrows deep underground in arid locations far from water. It only emerges to hunt for food."),
        PokedexPokemon(28, "Sandslash", Type::Ground, Type::None, false, 29.5f, 1.0f, "Curls up into a spiny ball when threatened. It can roll while curled up to attack or escape."),
        PokedexPokemon(29, "Nidoran♀", Type::Poison, Type::None, true, 7.0f, 0.4f, "Although small, its venomous barbs render this Pokémon dangerous. The female has smaller horns."),
        PokedexPokemon(30, "Nidorina", Type::Poison, Type::None, false, 20.0f, 0.8f, "When resting deep in its burrow, its barbs always retract. This is proof that it is relaxed."),
        PokedexPokemon(31, "Nidoqueen", Type::Poison, Type::Ground, false, 60.0f, 1.3f, "Its hard scales provide strong protection. It uses its hefty bulk to execute powerful moves."),
        PokedexPokemon(32, "Nidoran♂", Type::Poison, Type::None, true, 9.0f, 0.5f, "Stiffens its ears to sense danger. The larger its horns, the more powerful its secreted venom."),
        PokedexPokemon(33, "Nidorino", Type::Poison, Type::None, false, 19.5f, 0.9f, "An aggressive Pokémon that is quick to attack. The horn on its head secretes a powerful venom."),
        PokedexPokemon(34, "Nidoking", Type::Poison, Type::Ground, false, 62.0f, 1.4f, "It uses its powerful tail in battle to smash, constrict, then break the prey's bones."),
        PokedexPokemon(35, "Clefairy", Type::Fairy, Type::None, true, 7.5f, 0.6f, "Its magical and cute appeal has many admirers. It is rare and found only in certain areas."),
        PokedexPokemon(36, "Clefable", Type::Fairy, Type::None, false, 40.0f, 1.3f, "A timid fairy Pokémon that is rarely seen. It will run and hide the moment it senses people."),
        PokedexPokemon(37, "Vulpix", Type::Fire, Type::None, true, 9.9f, 0.6f, "At the time of birth, it has just one tail. The tail splits from its tip as it grows older."),
        PokedexPokemon(38, "Ninetales", Type::Fire, Type::None, false, 19.9f, 1.1f, "Very smart and very vengeful. Grabbing one of its many tails could result in a 1000-year curse."),
        PokedexPokemon(39, "Jigglypuff", Type::Normal, Type::Fairy, true, 5.5f, 0.5f, "When its huge eyes light up, it sings a mysteriously soothing melody that lulls its enemies to sleep."),
        PokedexPokemon(40, "Wigglytuff", Type::Normal, Type::Fairy, false, 12.0f, 1.0f, "Its body is very elastic. By inhaling deeply, it can continue to inflate itself without limit."),
        PokedexPokemon(41, "Zubat", Type::Poison, Type::Flying, true, 7.5f, 0.8f, "Forms colonies in perpetually dark places. Uses ultrasonic waves to identify and approach targets."),
        PokedexPokemon(42, "Golbat", Type::Poison, Type::Flying, false, 55.0f, 1.6f, "Once it strikes, it will not stop draining energy from the victim even if it gets too heavy to fly."),
        PokedexPokemon(43, "Oddish", Type::Grass, Type::Poison, true, 5.4f, 0.5f, "During the day, it keeps its face buried in the ground. At night, it wanders around sowing its seeds."),
        PokedexPokemon(44, "Gloom", Type::Grass, Type::Poison, false, 8.6f, 0.8f, "The fluid that oozes from its mouth isn't drool. It is a nectar that is used to attract prey."),
        PokedexPokemon(45, "Vileplume", Type::Grass, Type::Poison, false, 18.6f, 1.2f, "The larger its petals, the more toxic pollen it contains. Its big head is heavy and hard to hold up."),
        PokedexPokemon(46, "Paras", Type::Bug, Type::Grass, true, 5.4f, 0.3f, "Burrows to suck tree roots. The mushrooms on its back grow by drawing nutrients from the bug host."),
        PokedexPokemon(47, "Parasect", Type::Bug, Type::Grass, false, 29.5f, 1.0f, "A host-parasite pair in which the parasite mushroom has taken over the host bug. Prefers damp places."),
        PokedexPokemon(48, "Venonat", Type::Bug, Type::Poison, true, 30.0f, 1.0f, "Lives in the shadows of tall trees where it eats insects. It is attracted by light at night."),
        PokedexPokemon(49, "Venomoth", Type::Bug, Type::Poison, false, 12.5f, 1.5f, "The wings are covered with dustlike scales. Every time it flaps its wings, it loses highly toxic dust."),
        PokedexPokemon(50, "Diglett", Type::Ground, Type::None, true, 0.8f, 0.2f, "Lives about one yard underground where it feeds on plant roots. It sometimes appears above ground."),
        PokedexPokemon(51, "Dugtrio", Type::Ground, Type::None, false, 33.3f, 0.7f, "A team of Diglett triplets. It triggers huge earthquakes by burrowing 60 miles underground."),
        PokedexPokemon(52, "Meowth", Type::Normal, Type::None, true, 4.2f, 0.4f, "Adores round objects. It wanders the streets on a nightly basis to look for dropped loose change."),
        PokedexPokemon(53, "Persian", Type::Normal, Type::None, false, 32.0f, 1.0f, "Although its fur has many admirers, it is tough to raise as a pet because of its fickle meanness."),
        PokedexPokemon(54, "Psyduck", Type::Water, Type::None, true, 19.6f, 0.8f, "While lulling its enemies with its vacant look, this wily Pokémon will use psychokinetic powers."),
        PokedexPokemon(55, "Golduck", Type::Water, Type::None, false, 76.6f, 1.7f, "Often seen swimming elegantly by lakeshores. It is often mistaken for the Japanese monster, Kappa."),
        PokedexPokemon(56, "Mankey", Type::Fighting, Type::None, true, 28.0f, 0.5f, "Extremely quick to anger. It could be docile one moment then thrashing away the next instant."),
        PokedexPokemon(57, "Primeape", Type::Fighting, Type::None, false, 32.0f, 1.0f, "Always furious and tenacious to boot. It will not abandon chasing its quarry until it is caught."),
        PokedexPokemon(58, "Growlithe", Type::Fire, Type::None, true, 19.0f, 0.7f, "Very friendly and faithful to people. It will try to repel enemies by barking and biting."),
        PokedexPokemon(59, "Arcanine", Type::Fire, Type::None, false, 155.0f, 1.9f, "A Pokémon that has been admired since the past for its beauty. It runs agilely as if on wings."),
        PokedexPokemon(60, "Poliwag", Type::Water, Type::None, true, 12.4f, 0.6f, "Its newly grown legs prevent it from walking well. It appears to prefer swimming over walking."),
        PokedexPokemon(61, "Poliwhirl", Type::Water, Type::None, false, 20.0f, 1.0f, "Capable of living in or out of water. When out of water, it sweats to keep its body slimy."),
        PokedexPokemon(62, "Poliwrath", Type::Water, Type::Fighting, false, 54.0f, 1.3f, "An adept swimmer at both the front crawl and breaststroke. Easily overtakes the best human swimmers."),
        PokedexPokemon(63, "Abra", Type::Psychic, Type::None, true, 19.5f, 0.9f, "Using its ability to read minds, it will identify impending danger and teleport to safety."),
        PokedexPokemon(64, "Kadabra", Type::Psychic, Type::None, false, 56.5f, 1.3f, "It emits special alpha waves from its body that induce headaches just by being close by."),
        PokedexPokemon(65, "Alakazam", Type::Psychic, Type::None, false, 48.0f, 1.5f, "Its brain can outperform a supercomputer. Its intelligence quotient is said to be 5,000."),
        PokedexPokemon(66, "Machop", Type::Fighting, Type::None, true, 19.5f, 0.8f, "Loves to build its muscles. It trains in all styles of martial arts to become even stronger."),
        PokedexPokemon(67, "Machoke", Type::Fighting, Type::None, false, 70.5f, 1.5f, "Its muscular body is so powerful, it must wear a power-save belt to be able to regulate its motions."),
        PokedexPokemon(68, "Machamp", Type::Fighting, Type::None, false, 130.0f, 1.6f, "Using its heavy muscles, it throws powerful punches that can send the victim clear over the horizon."),
        PokedexPokemon(69, "Bellsprout", Type::Grass, Type::Poison, true, 4.0f, 0.7f, "A carnivorous Pokémon that traps and eats bugs. It appears to use its root feet to replenish moisture."),
        PokedexPokemon(70, "Weepinbell", Type::Grass, Type::Poison, false, 6.4f, 1.0f, "It spits out poison powder to immobilize the enemy and then finishes it with a spray of acid."),
        PokedexPokemon(71, "Victreebel", Type::Grass, Type::Poison, false, 15.5f, 1.7f, "Said to live in huge colonies deep in jungles, although no one has ever returned from there."),
        PokedexPokemon(72, "Tentacool", Type::Water, Type::Poison, true, 45.5f, 0.9f, "Drifts in shallow seas. Anglers who hook them by accident are often punished by its stinging acid."),
        PokedexPokemon(73, "Tentacruel", Type::Water, Type::Poison, false, 55.0f, 1.6f, "The tentacles are normally kept short. On hunts, they are extended to ensnare and immobilize prey."),
        PokedexPokemon(74, "Geodude", Type::Rock, Type::Ground, true, 20.0f, 0.4f, "Found in fields and mountains. Mistaking them for boulders, people often step or trip on them."),
        PokedexPokemon(75, "Graveler", Type::Rock, Type::Ground, false, 105.0f, 1.0f, "Rolls down slopes to move. It rolls over any obstacle without slowing or changing its direction."),
        PokedexPokemon(76, "Golem", Type::Rock, Type::Ground, false, 300.0f, 1.4f, "Its boulder-like body is extremely hard. It can easily withstand dynamite blasts without damage."),
        PokedexPokemon(77, "Ponyta", Type::Fire, Type::None, true, 30.0f, 1.0f, "Its hooves are 10 times harder than diamonds. It can trample anything completely flat in little time."),
        PokedexPokemon(78, "Rapidash", Type::Fire, Type::None, false, 95.0f, 1.7f, "Just loves to run. If it sees something faster than itself, it will give chase at top speed."),
        PokedexPokemon(79, "Slowpoke", Type::Water, Type::Psychic, true, 36.0f, 1.2f, "Incredibly slow and sluggish. It is quite content to loll about without worrying about the time."),
        PokedexPokemon(80, "Slowbro", Type::Water, Type::Psychic, false, 78.5f, 1.6f, "The Shellder that is latched onto Slowpoke's tail is said to feed on the host's leftover scraps."),
        PokedexPokemon(81, "Magnemite", Type::Electric, Type::Steel, true, 6.0f, 0.3f, "Uses anti-gravity to stay suspended. Appears without warning and uses Thunder Wave and similar moves."),
        PokedexPokemon(82, "Magneton", Type::Electric, Type::Steel, false, 60.0f, 1.0f, "Formed by several Magnemites linked together. They frequently appear when sunspots flare up."),
        PokedexPokemon(83, "Farfetch'd", Type::Normal, Type::Flying, true, 15.0f, 0.8f, "The plant stalk it holds is its weapon. The stalk is used like a sword to cut all sorts of things."),
        PokedexPokemon(84, "Doduo", Type::Normal, Type::Flying, true, 39.2f, 1.4f, "A bird that makes up for its poor flying with its fast foot speed. Leaves giant footprints."),
        PokedexPokemon(85, "Dodrio", Type::Normal, Type::Flying, false, 85.2f, 1.8f, "Uses its three brains to execute complex plans. While two heads sleep, one head stays awake."),
        PokedexPokemon(86, "Seel", Type::Water, Type::None, true, 90.0f, 1.1f, "The light blue fur that covers it keeps it protected against the cold. It loves iceberg-filled oceans."),
        PokedexPokemon(87, "Dewgong", Type::Water, Type::Ice, false, 120.0f, 1.7f, "Stores thermal energy in its body. Swims at a steady eight knots even in intensely cold waters."),
        PokedexPokemon(88, "Grimer", Type::Poison, Type::None, true, 30.0f, 0.9f, "Appears in filthy areas. It thrives by sucking up polluted sludge that is pumped out of factories."),
        PokedexPokemon(89, "Muk", Type::Poison, Type::None, false, 30.0f, 1.2f, "Thickly covered with a filthy, vile sludge. It is so toxic, even its footprints contain poison."),
        PokedexPokemon(90, "Shellder", Type::Water, Type::None, true, 4.0f, 0.3f, "Its hard shell repels any kind of attack. It is vulnerable only when its shell is open."),
        PokedexPokemon(91, "Cloyster", Type::Water, Type::Ice, false, 132.5f, 1.5f, "When attacked, it launches its horns in quick volleys. Its innards have never been seen."),
        PokedexPokemon(92, "Gastly", Type::Ghost, Type::Poison, true, 0.1f, 1.3f, "Almost invisible, this gaseous Pokémon cloaks the target and puts it to sleep without notice."),
        PokedexPokemon(93, "Haunter", Type::Ghost, Type::Poison, false, 0.1f, 1.6f, "Because of its ability to slip through block walls, it is said to be from another dimension."),
        PokedexPokemon(94, "Gengar", Type::Ghost, Type::Poison, false, 40.5f, 1.5f, "On the night of a full moon, if shadows move on their own and laugh, it must be Gengar's doing."),
        PokedexPokemon(95, "Onix", Type::Rock, Type::Ground, true, 210.0f, 8.8f, "As it grows, the stone portions of its body harden to become similar to a diamond, but colored black."),
        PokedexPokemon(96, "Drowzee", Type::Psychic, Type::None, true, 32.4f, 1.0f, "Puts enemies to sleep, then eats their dreams. Occasionally gets sick from eating only bad dreams."),
        PokedexPokemon(97, "Hypno", Type::Psychic, Type::None, false, 75.6f, 1.6f, "When it locks eyes with an enemy, it will use a mix of PSI moves such as Hypnosis and Confusion."),
        PokedexPokemon(98, "Krabby", Type::Water, Type::None, true, 6.5f, 0.4f, "Its pincers are not only powerful weapons, they are used for balance when walking sideways."),
        PokedexPokemon(99, "Kingler", Type::Water, Type::None, false, 60.0f, 1.3f, "The large pincer has 10,000-horsepower strength. However, it is so heavy, it is difficult to aim."),
        PokedexPokemon(100, "Voltorb", Type::Electric, Type::None, true, 10.4f, 0.5f, "Usually found in power plants. Easily mistaken for a Poké Ball, they have zapped many people."),
        PokedexPokemon(101, "Electrode", Type::Electric, Type::None, false, 66.6f, 1.2f, "It stores electric energy under very high pressure. It often explodes with little or no provocation."),
        PokedexPokemon(102, "Exeggcute", Type::Grass, Type::Psychic, true, 2.5f, 0.4f, "Often mistaken for eggs. When disturbed, they quickly gather and attack in swarms."),
        PokedexPokemon(103, "Exeggutor", Type::Grass, Type::Psychic, false, 120.0f, 2.0f, "Its cries are very noisy. This is because each of the three heads thinks about whatever it likes."),
        PokedexPokemon(104, "Cubone", Type::Ground, Type::None, true, 6.5f, 0.4f, "Wears the skull of its deceased mother. Its cries echo inside the skull and come out as a sad melody."),
        PokedexPokemon(105, "Marowak", Type::Ground, Type::None, false, 45.0f, 1.0f, "The bone it holds is its key weapon. It throws the bone skillfully like a boomerang to KO targets."),
        PokedexPokemon(106, "Hitmonlee", Type::Fighting, Type::None, false, 49.8f, 1.5f, "When in a hurry, its legs lengthen progressively. It runs smoothly with extra long, loping strides."),
        PokedexPokemon(107, "Hitmonchan", Type::Fighting, Type::None, false, 50.2f, 1.4f, "While apparently doing nothing, it fires punches in lightning-fast volleys that are impossible to see."),
        PokedexPokemon(108, "Lickitung", Type::Normal, Type::None, true, 65.5f, 1.2f, "Its tongue can be extended like a chameleon's. It leaves a tingling sensation when it licks enemies."),
        PokedexPokemon(109, "Koffing", Type::Poison, Type::None, true, 1.0f, 0.6f, "Because it stores several kinds of toxic gases in its body, it is prone to exploding without warning."),
        PokedexPokemon(110, "Weezing", Type::Poison, Type::None, false, 9.5f, 1.2f, "If one of the twin Koffing inflates, the other one deflates. It constantly mixes its poisonous gases."),
        PokedexPokemon(111, "Rhyhorn", Type::Ground, Type::Rock, true, 115.0f, 1.0f, "Its massive bones are 1000 times harder than human bones. It can easily knock a trailer flying."),
        PokedexPokemon(112, "Rhydon", Type::Ground, Type::Rock, false, 120.0f, 1.9f, "Protected by an armor-like hide, it is capable of living in molten lava of 3,600 degrees Fahrenheit."),
        PokedexPokemon(113, "Chansey", Type::Normal, Type::None, true, 34.6f, 1.1f, "A rare and elusive Pokémon that is said to bring happiness to those who manage to catch one."),
        PokedexPokemon(114, "Tangela", Type::Grass, Type::None, true, 35.0f, 1.0f, "The whole body is swathed with wide vines that are similar to seaweed. Its vines shake as it walks."),
        PokedexPokemon(115, "Kangaskhan", Type::Normal, Type::None, false, 80.0f, 2.2f, "The female raises its offspring in a pouch on its belly. It is skilled at attacking using Comet Punch."),
        PokedexPokemon(116, "Horsea", Type::Water, Type::None, true, 8.0f, 0.4f, "Known to shoot down flying bugs with precision blasts of ink from the surface of the water."),
        PokedexPokemon(117, "Seadra", Type::Water, Type::None, false, 25.0f, 1.2f, "Touching the back fin causes numbness. It hooks its tail to coral to stay in place while sleeping."),
        PokedexPokemon(118, "Goldeen", Type::Water, Type::None, true, 15.0f, 0.6f, "Its dorsal and pectoral fins are strongly developed like muscles. It can swim at a speed of five knots."),
        PokedexPokemon(119, "Seaking", Type::Water, Type::None, false, 39.0f, 1.3f, "In the autumn spawning season, they can be seen swimming powerfully up rivers and creeks."),
        PokedexPokemon(120, "Staryu", Type::Water, Type::None, true, 34.5f, 0.8f, "An enigmatic Pokémon that can effortlessly regenerate any appendage it loses in battle."),
        PokedexPokemon(121, "Starmie", Type::Water, Type::Psychic, false, 80.0f, 1.1f, "This Pokémon has a geometric body. Because of its body, the locals suspect that it is an alien creature."),
        PokedexPokemon(122, "Mr. Mime", Type::Psychic, Type::Fairy, false, 54.5f, 1.3f, "If interrupted while it is miming, it will slap around the offender with its broad hands."),
        PokedexPokemon(123, "Scyther", Type::Bug, Type::Flying, true, 56.0f, 1.5f, "With ninja-like agility and speed, it can create the illusion that there is more than one."),
        PokedexPokemon(124, "Jynx", Type::Ice, Type::Psychic, false, 40.6f, 1.4f, "It seductively wiggles its hips as it walks. It can cause people to dance in unison with it."),
        PokedexPokemon(125, "Electabuzz", Type::Electric, Type::None, false, 30.0f, 1.1f, "Normally found near power plants, they can wander away and cause major blackouts in cities."),
        PokedexPokemon(126, "Magmar", Type::Fire, Type::None, false, 44.5f, 1.3f, "Its body always burns with an orange glow that enables it to hide perfectly among flames."),
        PokedexPokemon(127, "Pinsir", Type::Bug, Type::None, true, 55.0f, 1.5f, "If it fails to crush the foe in its pincers, it will swing it around and toss it hard."),
        PokedexPokemon(128, "Tauros", Type::Normal, Type::None, false, 88.4f, 1.4f, "When it targets an enemy, it charges furiously while whipping its body with its long tails."),
        PokedexPokemon(129, "Magikarp", Type::Water, Type::None, true, 10.0f, 0.9f, "In the distant past, it was somewhat stronger than the horribly weak descendants that exist today."),
        PokedexPokemon(130, "Gyarados", Type::Water, Type::Flying, false, 235.0f, 6.5f, "Rarely seen in the wild. Huge and vicious, it is capable of destroying entire cities in a rage."),
        PokedexPokemon(131, "Lapras", Type::Water, Type::Ice, false, 220.0f, 2.5f, "A Pokémon that has been overhunted almost to extinction. It can ferry people across the water."),
        PokedexPokemon(132, "Ditto", Type::Normal, Type::None, true, 4.0f, 0.3f, "Capable of copying an enemy's genetic code to instantly transform itself into a duplicate of the enemy."),
        PokedexPokemon(133, "Eevee", Type::Normal, Type::None, true, 6.5f, 0.3f, "Its genetic code is irregular. It may mutate if it is exposed to radiation from element stones."),
        PokedexPokemon(134, "Vaporeon", Type::Water, Type::None, false, 29.0f, 1.0f, "Lives close to water. Its long tail is ridged with a fin that is often mistaken for a mermaid's."),
        PokedexPokemon(135, "Jolteon", Type::Electric, Type::None, false, 24.5f, 0.8f, "It accumulates negative ions in the atmosphere to blast out 10000-volt lightning bolts."),
        PokedexPokemon(136, "Flareon", Type::Fire, Type::None, false, 25.0f, 0.9f, "When it catches prey or finds berries, it breathes fire on them until they are well done and tasty."),
        PokedexPokemon(137, "Porygon", Type::Normal, Type::None, false, 36.5f, 0.8f, "The only Pokémon people anticipate can fly into space. None has managed the feat yet, however."),
        PokedexPokemon(138, "Omanyte", Type::Rock, Type::Water, true, 7.5f, 0.4f, "Although long extinct, in rare cases, it can be genetically resurrected from fossils."),
        PokedexPokemon(139, "Omastar", Type::Rock, Type::Water, false, 35.0f, 1.0f, "Its heavy shell allowed it to reach only nearby food. This became a factor in its extinction."),
        PokedexPokemon(140, "Kabuto", Type::Rock, Type::Water, true, 11.5f, 0.5f, "A Pokémon that was resurrected from a fossil found in what was once the ocean floor eons ago."),
        PokedexPokemon(141, "Kabutops", Type::Rock, Type::Water, false, 40.5f, 1.3f, "Its sleek shape is perfect for swimming. It slashes prey with its claws and drains the body fluids."),
        PokedexPokemon(142, "Aerodactyl", Type::Rock, Type::Flying, false, 59.0f, 1.8f, "A ferocious, prehistoric Pokémon that goes for the enemy's throat with its serrated saw-like fangs."),
        PokedexPokemon(143, "Snorlax", Type::Normal, Type::None, false, 460.0f, 2.1f, "Very lazy. Just eats and sleeps. As its rotund bulk builds, it becomes steadily more slothful."),
        PokedexPokemon(144, "Articuno", Type::Ice, Type::Flying, false, 55.4f, 1.7f, "A legendary bird Pokémon that is said to appear to doomed people who are lost in icy mountains."),
        PokedexPokemon(145, "Zapdos", Type::Electric, Type::Flying, false, 52.6f, 1.6f, "A legendary bird Pokémon that is said to appear from clouds while dropping enormous lightning bolts."),
        PokedexPokemon(146, "Moltres", Type::Fire, Type::Flying, false, 60.0f, 2.0f, "Known as the legendary bird of fire. Every flap of its wings creates a dazzling flash of flames."),
        PokedexPokemon(147, "Dratini", Type::Dragon, Type::None, true, 3.3f, 1.8f, "Long considered a mythical Pokémon until recently when a small colony was found living underwater."),
        PokedexPokemon(148, "Dragonair", Type::Dragon, Type::None, false, 16.5f, 4.0f, "A mystical Pokémon that exudes a gentle aura. Has the ability to change climate conditions."),
        PokedexPokemon(149, "Dragonite", Type::Dragon, Type::Flying, false, 210.0f, 2.2f, "An extremely rarely seen marine Pokémon. Its intelligence is said to match that of humans."),
        PokedexPokemon(150, "Mewtwo", Type::Psychic, Type::None, false, 122.0f, 2.0f, "It was created by a scientist after years of horrific gene splicing and DNA engineering experiments."),
        PokedexPokemon(151, "Mew", Type::Psychic, Type::None, false, 4.0f, 0.4f, "So rare that it is still said to be a mirage by many experts. Only a few people have seen it worldwide.")
    };
#endif
