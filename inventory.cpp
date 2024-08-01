#pragma once

#include "pokemon.hpp"
#include "pokemon.cpp"

#include "pokedex.cpp"

#include <iostream>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h> // For usleep
#include <cmath> // floor function 

class PokemonWindow
{
public:
    WINDOW *complete_pokemon_window;
    WINDOW *name_window;
    WINDOW *type_window;
    WINDOW *weight_window;
    WINDOW *height_window;
    WINDOW *hp_window;
    WINDOW *cp_window;
    WINDOW *defence_window;
    WINDOW *base_atk_window;
    WINDOW *base_atk_power_window;
    WINDOW *spec_atk_window;
    WINDOW *spec_atk_power_window;

    PokemonWindow(WINDOW *&main_window, int posy, int posx)
    {
        complete_pokemon_window = derwin(main_window, 11, 40, posy, posx);
        name_window = derwin(complete_pokemon_window, 1, 12, 1, 1);
        type_window = derwin(complete_pokemon_window, 1, 25, 1, 14);
        weight_window = derwin(complete_pokemon_window, 1, 19, 3, 1);
        height_window = derwin(complete_pokemon_window, 1, 18, 3, 21);
        hp_window = derwin(complete_pokemon_window, 1, 10, 5, 1);
        cp_window = derwin(complete_pokemon_window, 1, 11, 5, 12);
        defence_window = derwin(complete_pokemon_window, 1, 15, 5, 24);
        base_atk_window = derwin(complete_pokemon_window, 1, 28, 7, 1);
        base_atk_power_window = derwin(complete_pokemon_window, 1, 9, 7, 30);
        spec_atk_window = derwin(complete_pokemon_window, 1, 28, 9, 1);
        spec_atk_power_window = derwin(complete_pokemon_window, 1, 9, 9, 30);
    }
    // ~PokemonWindow()
    // {
    //     delwin(name_window);
    //     delwin(type_window);
    //     delwin(weight_window);
    //     delwin(height_window);
    //     delwin(hp_window);
    //     delwin(cp_window);
    //     delwin(defence_window);
    //     delwin(base_atk_window);
    //     delwin(base_atk_power_window);
    //     delwin(spec_atk_window);
    //     delwin(spec_atk_power_window);
    //     delwin(complete_pokemon_window);
    // }
};

WINDOW *drawAddButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *add_window = derwin(main_window, 3, 9, y, x);
    mvwprintw(add_window, 0, 0, "┌───┐");
    mvwprintw(add_window, 1, 0, "│ A │ Add");
    mvwprintw(add_window, 2, 0, "└───┘");
    wrefresh(add_window);
    return add_window;
}
WINDOW *drawDeleteButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *delete_window = derwin(main_window, 3, 12, y, x);
    mvwprintw(delete_window, 0, 0, "┌───┐");
    mvwprintw(delete_window, 1, 0, "│ D │ Delete");
    mvwprintw(delete_window, 2, 0, "└───┘");
    wrefresh(delete_window);
    return delete_window;
}
WINDOW *drawContinueButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *continue_window = derwin(main_window, 3, 18, y, x);
    mvwprintw(continue_window, 0, 0, "┌───────┐");
    mvwprintw(continue_window, 1, 0, "│ Enter │ Continue");
    mvwprintw(continue_window, 2, 0, "└───────┘");
    wrefresh(continue_window);
    return continue_window;
}
WINDOW *drawCompletePokemonButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *complete_pokemon_window = derwin(main_window, 3, 26, y, x);
    mvwprintw(complete_pokemon_window, 0, 0, "┌───────┐");
    mvwprintw(complete_pokemon_window, 1, 0, "│ Enter │ Complete Pokemon");
    mvwprintw(complete_pokemon_window, 2, 0, "└───────┘");
    wrefresh(complete_pokemon_window);
    return complete_pokemon_window;
}
void drawInfoPanelInventory(WINDOW *&main_window)
{
    drawAddButton(main_window, 31, 10);

    drawDeleteButton(main_window, 31, 22);

    drawMoveButtons(main_window, 31, 37);

    drawBackButton(main_window, 31, 62);
}
void clearWindow(WINDOW *&window)
{
    wclear(window);
    wrefresh(window);
}

void drawHighlightPokemonCount(WINDOW *&pokemon_count_window, int &input_index, int inventory_size)
{
    mvwprintw(pokemon_count_window, 0, 0, "┌───────┐");
    (inventory_size != 0) ? mvwprintw(pokemon_count_window, 1, 0, "│ %2d/%2d │", input_index + 1, inventory_size) : mvwprintw(pokemon_count_window, 1, 0, "│ %2d/%2d │", input_index, inventory_size);
    mvwprintw(pokemon_count_window, 2, 0, "└───────┘");
    wrefresh(pokemon_count_window);
}

void pushingPokemonWindows(WINDOW *&main_window, std::vector<PokemonWindow> &pokemon_windows)
{
    pokemon_windows.push_back(PokemonWindow(main_window, 4, 10));
    pokemon_windows.push_back(PokemonWindow(main_window, 4, 56));
    pokemon_windows.push_back(PokemonWindow(main_window, 4, 102));
    pokemon_windows.push_back(PokemonWindow(main_window, 17, 10));
    pokemon_windows.push_back(PokemonWindow(main_window, 17, 56));
    pokemon_windows.push_back(PokemonWindow(main_window, 17, 102));
}

void fillInventoryPokemonWindow([[maybe_unused]] WINDOW *&complete_pokemon_window)
{
    mvwprintw(complete_pokemon_window, 0, 0, "┌────────────┬─────────────────────────┐");
    mvwprintw(complete_pokemon_window, 1, 0, "│            │                         │");
    mvwprintw(complete_pokemon_window, 2, 0, "├────────────┴──────┬──────────────────┤");
    mvwprintw(complete_pokemon_window, 3, 0, "│                   │                  │");
    mvwprintw(complete_pokemon_window, 4, 0, "├──────────┬────────┴──┬───────────────┤");
    mvwprintw(complete_pokemon_window, 5, 0, "│          │           │               │");
    mvwprintw(complete_pokemon_window, 6, 0, "├──────────┴───────────┴─────┬─────────┤");
    mvwprintw(complete_pokemon_window, 7, 0, "│                            │         │");
    mvwprintw(complete_pokemon_window, 8, 0, "├────────────────────────────┼─────────┤");
    mvwprintw(complete_pokemon_window, 9, 0, "│                            │         │");
    mvwprintw(complete_pokemon_window, 10, 0, "└────────────────────────────┴─────────┘");
    wrefresh(complete_pokemon_window);
}
void emptyInventoryPokemonWindow([[maybe_unused]] WINDOW *&complete_pokemon_window)
{
    mvwprintw(complete_pokemon_window, 0, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 1, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 2, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 3, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 4, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 5, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 6, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 7, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 8, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 9, 0, "                                        ");
    mvwprintw(complete_pokemon_window, 10, 0, "                                        ");
    wrefresh(complete_pokemon_window);
}

// std::string returnWithRightPrecision(float attribute)
// {
//     std::ostringstream out;
//     out << std::fixed << std::setprecision(1) << attribute;
//     return out.str();
// }

std::vector<std::string> prepareForPassing(InventoryPokemon &examined_pokemon)
{
    std::vector<std::string> pass_vector;
    // printw("input index is %d", input_index);    /* debug */

    pass_vector.push_back(examined_pokemon.getName());

    pass_vector.push_back(returnWithRightPrecision(examined_pokemon.getWeight()));
    pass_vector.push_back(returnWithRightPrecision(examined_pokemon.getHeight()));

    pass_vector.push_back(std::to_string(examined_pokemon.getHP()));
    pass_vector.push_back(std::to_string(examined_pokemon.getCP()));
    pass_vector.push_back(std::to_string(examined_pokemon.getDefence()));

    return pass_vector;
}

void writingOutType(WINDOW *&type_window, Type type1, Type type2, [[maybe_unused]] bool highlight_flag)
{
    size_t offset;
    if (type2 == Type::None)
    {
        offset = TypeTtoS(type1).size() + 6; //"Type: "
    }
    else
    {
        offset = TypeTtoS(type1).size() + TypeTtoS(type2).size() + 1 + 6; // '/' + "Type: "
    }
    (highlight_flag) ? wattron(type_window, COLOR_PAIR(static_cast<short>(Type::Normal) + 20)) : wattron(type_window, COLOR_PAIR(static_cast<short>(Type::Normal)));
    mvwprintw(type_window, 0, (25 - static_cast<int>(offset)) / 2, "Type: ");
    (highlight_flag) ? wattroff(type_window, COLOR_PAIR(static_cast<short>(Type::Normal) + 20)) : wattroff(type_window, COLOR_PAIR(static_cast<short>(Type::Normal)));

    (highlight_flag) ? wattron(type_window, COLOR_PAIR(static_cast<short>(type1) + 20)) : wattron(type_window, COLOR_PAIR(static_cast<short>(type1)));
    wprintw(type_window, "%s", TypeTtoS(type1).c_str());
    (highlight_flag) ? wattroff(type_window, COLOR_PAIR(static_cast<short>(type1) + 20)) : wattroff(type_window, COLOR_PAIR(static_cast<short>(type1)));

    if (type2 != Type::None)
    {
        if (highlight_flag)
            wattron(type_window, A_REVERSE);
        wprintw(type_window, "/");
        if (highlight_flag)
            wattroff(type_window, A_REVERSE);
        (highlight_flag) ? wattron(type_window, COLOR_PAIR(static_cast<short>(type2) + 20)) : wattron(type_window, COLOR_PAIR(static_cast<short>(type2)));
        wprintw(type_window, "%s", TypeTtoS(type2).c_str());
        (highlight_flag) ? wattroff(type_window, COLOR_PAIR(static_cast<short>(type2) + 20)) : wattroff(type_window, COLOR_PAIR(static_cast<short>(type2)));
    }
}

void writingOutAttack([[maybe_unused]] WINDOW *&atk_window, [[maybe_unused]] WINDOW *&atk_power_window, [[maybe_unused]] Attack attack, [[maybe_unused]] Type type1, [[maybe_unused]] Type type2, [[maybe_unused]] bool highlight_flag)
{
#if 0 // redundant?
    if (!highlight_flag)
    { // de-highlighting the pokemon
        init_pair(static_cast<short>(Type::Normal), COLOR_WHITE, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Fire), 196, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Water), 4, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Electric), 3, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Grass), 34, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Ice), 81, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Fighting), 1, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Poison), 165, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Ground), 130, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Flying), 153, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Psychic), 207, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Bug), 106, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Rock), 142, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Ghost), 57, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Dragon), 33, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Dark), 247, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Steel), 252, COLOR_BLACK);
        init_pair(static_cast<short>(Type::Fairy), 219, COLOR_BLACK);
    }
    else
    { // highlighting the pokemon
        wbkgd(atk_window, A_REVERSE);
        wbkgd(atk_power_window, A_REVERSE);
        init_pair(static_cast<short>(Type::Normal), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Fire), 196, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Water), 4, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Electric), 3, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Grass), 34, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Ice), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Fighting), 1, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Poison), 165, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Ground), 130, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Flying), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Psychic), 207, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Bug), 106, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Rock), 142, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Ghost), 57, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Dragon), 33, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Dark), 247, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Steel), COLOR_BLACK, COLOR_WHITE);
        init_pair(static_cast<short>(Type::Fairy), 219, COLOR_WHITE);
    }
#endif

    size_t name_offset = attack.getName().size() + 9; //"baseAtk: " or "specAtk: "
    if (highlight_flag)
        wattron(atk_window, A_REVERSE);
    if (attack.getPower() > 20)
        mvwprintw(atk_window, 0, (28 - static_cast<int>(name_offset)) / 2, "specAtk: "); // special attacks power should be greater than 20
    else
        mvwprintw(atk_window, 0, (28 - static_cast<int>(name_offset)) / 2, "baseAtk: "); // if not, then it's a base attack
    if (highlight_flag)
        wattroff(atk_window, A_REVERSE);

    (highlight_flag) ? wattron(atk_window, COLOR_PAIR(static_cast<short>(attack.getType()) + 20)) : wattron(atk_window, COLOR_PAIR(static_cast<short>(attack.getType())));
    wprintw(atk_window, "%s", attack.getName().c_str());
    (highlight_flag) ? wattroff(atk_window, COLOR_PAIR(static_cast<short>(attack.getType()) + 20)) : wattroff(atk_window, COLOR_PAIR(static_cast<short>(attack.getType())));

    size_t power_offset = std::to_string(attack.getPower()).size();
    if (type1 == attack.getType() || type2 == attack.getType())
    {
        power_offset += 4; //+20%
    }
    if (highlight_flag)
        wattron(atk_power_window, A_REVERSE);
    mvwprintw(atk_power_window, 0, (9 - static_cast<int>(power_offset) + 1) / 2, "%s", std::to_string(attack.getPower()).c_str());
    if (highlight_flag)
        wattroff(atk_power_window, A_REVERSE);
    if (type1 == attack.getType() || type2 == attack.getType())
    {
        (highlight_flag) ? wattron(atk_power_window, COLOR_PAIR(static_cast<short>(Type::Rock) + 20)) : wattron(atk_power_window, COLOR_PAIR(static_cast<short>(Type::Rock)));
        wprintw(atk_power_window, "+20%%");
        (highlight_flag) ? wattroff(atk_power_window, COLOR_PAIR(static_cast<short>(Type::Rock) + 20)) : wattroff(atk_power_window, COLOR_PAIR(static_cast<short>(Type::Rock)));
    }
}

void refreshInventoryPokemonWindow([[maybe_unused]] PokemonWindow &pokemon_window,
                                   [[maybe_unused]] const std::vector<InventoryPokemon> &inventory, [[maybe_unused]] int &input_index, [[maybe_unused]] bool highlight_flag)
{
    // wclear(pokemon_window.complete_pokemon_window); /* don't clear the borders */
    wclear(pokemon_window.name_window);
    wclear(pokemon_window.type_window);
    wclear(pokemon_window.weight_window);
    wclear(pokemon_window.height_window);
    wclear(pokemon_window.hp_window);
    wclear(pokemon_window.cp_window);
    wclear(pokemon_window.defence_window);
    wclear(pokemon_window.base_atk_window);
    wclear(pokemon_window.base_atk_power_window);
    wclear(pokemon_window.spec_atk_window);
    wclear(pokemon_window.spec_atk_power_window);

    if (highlight_flag)
    { // highlighting the pokemon
        wattron(pokemon_window.complete_pokemon_window, A_REVERSE);
        wattron(pokemon_window.name_window, A_REVERSE);
        wattron(pokemon_window.weight_window, A_REVERSE);
        wattron(pokemon_window.height_window, A_REVERSE);
        wattron(pokemon_window.hp_window, A_REVERSE);
        wattron(pokemon_window.cp_window, A_REVERSE);
        wattron(pokemon_window.defence_window, A_REVERSE);
    }
    InventoryPokemon examined_pokemon = inventory.at(static_cast<size_t>(input_index));
    [[maybe_unused]] std::vector<std::string> pass_vector = prepareForPassing(examined_pokemon);

#if 0 // debug
    for (size_t i = 0; i < pass_vector.size(); i++)
    {
        mvprintw(static_cast<int>(i),0, "%s",pass_vector.at(i).c_str());
    }
#endif

#if 1
    fillInventoryPokemonWindow(pokemon_window.complete_pokemon_window);
    wrefresh(pokemon_window.complete_pokemon_window);

    mvwprintw(pokemon_window.name_window, 0, (12 - static_cast<int>(pass_vector.at(0).size())) / 2, "%s", pass_vector.at(0).c_str());
    wrefresh(pokemon_window.name_window);

    writingOutType(pokemon_window.type_window, examined_pokemon.getType().first, examined_pokemon.getType().second, highlight_flag);
    wrefresh(pokemon_window.type_window);

    mvwprintw(pokemon_window.weight_window, 0, (19 - static_cast<int>(pass_vector.at(1).size()) - 7 - 2) / 2, "Weight: %skg", pass_vector.at(1).c_str());
    wrefresh(pokemon_window.weight_window);

    mvwprintw(pokemon_window.height_window, 0, (18 - static_cast<int>(pass_vector.at(2).size()) - 7 - 1) / 2, "Height: %sm", pass_vector.at(2).c_str());
    wrefresh(pokemon_window.height_window);

    mvwprintw(pokemon_window.hp_window, 0, (10 - static_cast<int>(pass_vector.at(3).size()) - 4) / 2, "HP: %s", pass_vector.at(3).c_str());
    wrefresh(pokemon_window.hp_window);

    mvwprintw(pokemon_window.cp_window, 0, (11 - static_cast<int>(pass_vector.at(4).size()) - 4) / 2, "CP: %s", pass_vector.at(4).c_str());
    wrefresh(pokemon_window.cp_window);

    mvwprintw(pokemon_window.defence_window, 0, (15 - static_cast<int>(pass_vector.at(5).size()) - 9) / 2, "Defence: %s", pass_vector.at(5).c_str());
    wrefresh(pokemon_window.defence_window);

    writingOutAttack(pokemon_window.base_atk_window, pokemon_window.base_atk_power_window, examined_pokemon.getBaseAttack(), examined_pokemon.getType().first, examined_pokemon.getType().second, highlight_flag);
    wrefresh(pokemon_window.base_atk_window);
    wrefresh(pokemon_window.base_atk_power_window);
    writingOutAttack(pokemon_window.spec_atk_window, pokemon_window.spec_atk_power_window, examined_pokemon.getSpecialAttack(), examined_pokemon.getType().first, examined_pokemon.getType().second, highlight_flag);
    wrefresh(pokemon_window.spec_atk_window);
    wrefresh(pokemon_window.spec_atk_power_window);

    if (highlight_flag)
    { // ending highlight
        wattroff(pokemon_window.complete_pokemon_window, A_REVERSE);
        wattroff(pokemon_window.name_window, A_REVERSE);
        wattroff(pokemon_window.weight_window, A_REVERSE);
        wattroff(pokemon_window.height_window, A_REVERSE);
        wattroff(pokemon_window.hp_window, A_REVERSE);
        wattroff(pokemon_window.cp_window, A_REVERSE);
        wattroff(pokemon_window.defence_window, A_REVERSE);
    }
#endif
}

void refreshInventoryFullFix(std::vector<PokemonWindow> &pokemon_windows,
                             const std::vector<InventoryPokemon> &inventory, int &input_index) // without usleep()
{
    [[maybe_unused]] int starting_pokemon_index = input_index - (input_index % 6);
    // refreshInventoryPokemonWindow(pokemon_windows.at(0), inventory, input_index, 0);

    for (PokemonWindow pokemon_window : pokemon_windows)
    {
        if (starting_pokemon_index < static_cast<int>(inventory.size()))
        {
            fillInventoryPokemonWindow(pokemon_window.complete_pokemon_window);
            (starting_pokemon_index == input_index) ? refreshInventoryPokemonWindow(pokemon_window, inventory, starting_pokemon_index, 1) : refreshInventoryPokemonWindow(pokemon_window, inventory, starting_pokemon_index, 0);
        }
        else
        {
            emptyInventoryPokemonWindow(pokemon_window.complete_pokemon_window);
        }
        starting_pokemon_index++;
    }
}
void refreshInventoryFull(std::vector<PokemonWindow> &pokemon_windows,
                          const std::vector<InventoryPokemon> &inventory, int &input_index)
{
    [[maybe_unused]] int starting_pokemon_index = input_index - (input_index % 6);
    // refreshInventoryPokemonWindow(pokemon_windows.at(0), inventory, input_index, 0);

    for (PokemonWindow pokemon_window : pokemon_windows)
    {
        if (starting_pokemon_index < static_cast<int>(inventory.size()))
        {
            fillInventoryPokemonWindow(pokemon_window.complete_pokemon_window);
            (starting_pokemon_index == input_index) ? refreshInventoryPokemonWindow(pokemon_window, inventory, starting_pokemon_index, 1) : refreshInventoryPokemonWindow(pokemon_window, inventory, starting_pokemon_index, 0);
        }
        else
        {
            emptyInventoryPokemonWindow(pokemon_window.complete_pokemon_window);
        }
        starting_pokemon_index++;
        // usleep(25000);
    }
}
// bool isWindowTooSmall()
// {
//     return (LINES < 40 || COLS < 155);
// }
// void displayResizeMessage()
// {
//     clear();
//     mvwprintw(stdscr, LINES / 2, (COLS - 25) / 2, "Expand window to continue");
//     refresh();
// }

void resizeWindowsFix(WINDOW *&main_window, std::vector<PokemonWindow> &pokemon_windows, WINDOW *&pokemon_count_window, std::vector<InventoryPokemon> &inventory, int &input_index)
{
    clear();
    refresh();
    wresize(main_window, 37, 152);
    mvwin(main_window, 0, 0);
    wclear(main_window);
    box(main_window, 0, 0);
    wrefresh(main_window);

    pokemon_windows.clear();
    pushingPokemonWindows(main_window, pokemon_windows);

    refreshInventoryFullFix(pokemon_windows, inventory, input_index);

    wresize(pokemon_count_window, 3, 9);
    mvwin(pokemon_count_window, 31, 133);
    wclear(pokemon_count_window);
    wrefresh(pokemon_count_window);

    drawInfoPanelInventory(main_window);
    drawHighlightPokemonCount(pokemon_count_window, input_index, static_cast<int>(inventory.size()));
}
void deleteConfirmation(WINDOW *&main_window, std::vector<InventoryPokemon> &inventory, int &input_index)
{
    wclear(main_window);
    box(main_window, 0, 0);
    if (inventory.size() == 0)
    {
        mvwprintw(main_window, 16, 64, "Your inventory is empty.");
        wrefresh(main_window);
        return;
    }

    PokemonWindow temporary_pokemon_window = PokemonWindow(main_window, 13, 30);
    refreshInventoryPokemonWindow(temporary_pokemon_window, inventory, input_index, 0);
    mvwprintw(main_window, 17, 80, "Do you really want to delete this Pokemon?");
    wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
    mvwprintw(main_window, 19, 98, "Y");
    wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
    wprintw(main_window, "/");
    wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
    wprintw(main_window, "N");
    wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
    wrefresh(main_window);
    int ch;
    bool window_too_small = false;
    while ((ch = getch()) != 'n')
    {
        if (ch == KEY_RESIZE)
        {
            if (isWindowTooSmall())
            {
                window_too_small = true;
                displayResizeMessage();
            }
            else if (window_too_small) // window isn't too small, but the flag is still true
            {
                window_too_small = false;
                clear();
                refresh();
                wresize(main_window, 37, 152);
                mvwin(main_window, 0, 0);
                wclear(main_window);
                box(main_window, 0, 0);
                temporary_pokemon_window = PokemonWindow(main_window, 13, 30);
                refreshInventoryPokemonWindow(temporary_pokemon_window, inventory, input_index, 0);
                mvwprintw(main_window, 17, 80, "Do you really want to delete this Pokemon?");
                wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
                mvwprintw(main_window, 19, 98, "Y");
                wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
                wprintw(main_window, "/");
                wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
                wprintw(main_window, "N");
                wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
                wrefresh(main_window);
            }
            else
            {
                clear();
                refresh();
                wresize(main_window, 37, 152);
                mvwin(main_window, 0, 0);
                wclear(main_window);
                box(main_window, 0, 0);
                temporary_pokemon_window = PokemonWindow(main_window, 13, 30);
                refreshInventoryPokemonWindow(temporary_pokemon_window, inventory, input_index, 0);
                mvwprintw(main_window, 17, 80, "Do you really want to delete this Pokemon?");
                wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
                mvwprintw(main_window, 19, 98, "Y");
                wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Grass)));
                wprintw(main_window, "/");
                wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
                wprintw(main_window, "N");
                wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Fire)));
                wrefresh(main_window);
                wrefresh(main_window);
            }
            continue;
        }

        if (window_too_small)
        {
            continue; // ignore input while the window is too small
        }
        if (ch == 'y')
        {
            inventory.erase(inventory.begin() + input_index);
            break;
        }
    }
    wclear(main_window);
    box(main_window, 0, 0);
    wrefresh(main_window);
    input_index = 0;
}

void addRefreshNameAndType(WINDOW *&name_window, WINDOW *&type_window, std::vector<PokedexPokemon> &pokedex, int &x, int &y)
{
    wclear(name_window);
    wclear(type_window);
    mvwprintw(name_window, 0, (12 - static_cast<int>(pokedex.at(static_cast<unsigned long>(y * 15 + x)).getName().size())) / 2, "%s", pokedex.at(static_cast<unsigned long>(y * 15 + x)).getName().c_str());
    wrefresh(name_window);
    writingOutType(type_window, pokedex.at(static_cast<unsigned long>(y * 15 + x)).getType().first, pokedex.at(static_cast<unsigned long>(y * 15 + x)).getType().second, 0);
    wrefresh(type_window);
}
float weightOrHeightSelect(WINDOW *&main_window, PokedexPokemon &pokedex_pokemon, const char *w_or_h_string)
{
    curs_set(TRUE); // blinking cursor
    float pokedex_pokemon_attribute = (w_or_h_string[0]=='w') ? pokedex_pokemon.getAvgWeight() : pokedex_pokemon.getAvgHeight();
    float lower_bound = static_cast<float>(floor(pokedex_pokemon_attribute*0.7*10)/10);
    float upper_bound = static_cast<float>(floor(pokedex_pokemon_attribute*1.3*10)/10);
    WINDOW *continue_button = drawContinueButton(main_window, 31, 122);

    WINDOW *message_window = derwin(main_window, 3, 54, 19, 28); // Position message_window below input_window
    // box(message_window, 0, 0);
    mvwprintw(message_window, 1, 0, "%s's %s should be between %.1f and %.1f%s", 
              pokedex_pokemon.getName().c_str(), 
              w_or_h_string, 
              lower_bound,
              upper_bound,
              (w_or_h_string[0]=='w') ? "kg" : "m"
              );
              
    wrefresh(message_window);

    WINDOW *input_window = derwin(main_window, 3, 29, 16, 40);
    box(input_window, 0, 0);
    mvwprintw(input_window, 1, 2, "Enter %s here: ", w_or_h_string);
    wrefresh(input_window);


    std::string input_str;
    int before_dot_counter = 0;
    int after_dot_counter = 0;
    bool dot_flag = false;
    [[maybe_unused]] int ch;
    while ((ch = getch())) // stop the while loop at Enter key
    {
        if (((ch >= '0' && ch <= '9') || (ch == '.' && input_str.find('.') == std::string::npos))) // correct character check, no-more-than-one-dot check
        {
            if (ch == '.')
                dot_flag = true;
            if ((before_dot_counter < 3 && dot_flag == false) || (after_dot_counter < 1 && dot_flag == true)) // check for the amount of characters before and after dot, allow inside if there are already 3 characters before dot, but we are writing numbers to decimal places
            {
                if (ch != '.')
                {
                    (dot_flag) ? after_dot_counter++ : before_dot_counter++;
                }

                input_str.push_back(static_cast<char>(ch));
                mvwprintw(input_window, 1, 21, "%s", input_str.c_str());
                wrefresh(input_window);
            }
        }
        else if ((ch == 8 || ch == 127) && input_str.size() != 0) // backspace or delete
        {
            char last_character = input_str.back();
            if (last_character == '.')
            {
                dot_flag = false;
            }
            else
            {
                (dot_flag) ? after_dot_counter-- : before_dot_counter--;
            }
            input_str.pop_back();
            wclear(input_window);
            box(input_window, 0, 0);
            mvwprintw(input_window, 1, 2, "Enter %s here: ", w_or_h_string);
            mvwprintw(input_window, 1, 21, "%s", input_str.c_str());
            wrefresh(input_window);
        }
        else if (ch == '\n')
        {
            if(input_str.empty()) continue; // empty input
            if(input_str[0] == '.' && after_dot_counter == 0) continue; // only dot written
            if ((std::stof(input_str) < lower_bound || (std::stof(input_str)) > upper_bound))
                continue;
            else
                break;
        }
    }
    std::stringstream ss(input_str);
    float decimal_number;
    ss >> decimal_number;
    wclear(input_window);
    wrefresh(input_window);

    curs_set(FALSE);
    clearWindow(message_window);
    clearWindow(continue_button);

    return decimal_number;
}
int hpCpDefSelect(WINDOW *&main_window, const char *hp_cp_def_string)
{
    curs_set(TRUE);

    WINDOW *continue_button = drawContinueButton(main_window, 31, 122);

    WINDOW *input_window = derwin(main_window, 3, 25, 17, 42);
    box(input_window, 0, 0);
    mvwprintw(input_window, 1, 2, "Enter %s here: ", hp_cp_def_string);
    wrefresh(input_window);

    std::string input_str;

    bool def_flag = strcmp(hp_cp_def_string, "Def");
    [[maybe_unused]] int number_counter = 0;
    [[maybe_unused]] int ch;
    while ((ch = getch())) // stop the while loop at Enter key and the right amount of characters
    {
        if ((ch >= '0' && ch <= '9')) // correct character check
        {
            if (input_str.size() >= 4)
                continue;

            number_counter++;
            input_str.push_back(static_cast<char>(ch));
            mvwprintw(input_window, 1, (def_flag) ? 17 : 18, "%s", input_str.c_str());
            wrefresh(input_window);
        }
        else if ((ch == 8 || ch == 127) && input_str.size() != 0) // backspace or delete
        {
            number_counter--;
            input_str.pop_back();
            wclear(input_window);
            box(input_window, 0, 0);
            mvwprintw(input_window, 1, 2, "Enter %s here: ", hp_cp_def_string);
            mvwprintw(input_window, 1, (def_flag) ? 17 : 18, "%s", input_str.c_str());
            wrefresh(input_window);
        }
        else if (ch == '\n')
        {
            if (number_counter < 2)
                continue;
            else
                break;
        }
    }

    std::stringstream ss(input_str);
    int int_number;
    ss >> int_number;
    wclear(input_window);
    wrefresh(input_window);

    curs_set(FALSE);

    clearWindow(continue_button);

    return int_number;
}

WINDOW *addBaseAttackTable(WINDOW *&main_window)
{
    WINDOW *base_atk_table_window = derwin(main_window, 29, 81, 4, 13);
    mvwprintw(base_atk_table_window, 0, 0, "┌───────────────────┬───────────────────┬───────────────────┬───────────────────┐");
    mvwprintw(base_atk_table_window, 1, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 2, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 3, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 4, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 5, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 6, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 7, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 8, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 9, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 10, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 11, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 12, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 13, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 14, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 15, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 16, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 17, 0, "│                   │                   │                   │                   │");
    mvwprintw(base_atk_table_window, 18, 0, "├───────────────────┼───────────────────┼───────────────────┼───────────────────┘");
    mvwprintw(base_atk_table_window, 19, 0, "│                   │                   │                   │");
    mvwprintw(base_atk_table_window, 20, 0, "├───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 21, 0, "│                   │                   │                   │");
    mvwprintw(base_atk_table_window, 22, 0, "├───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 23, 0, "│                   │                   │                   │");
    mvwprintw(base_atk_table_window, 24, 0, "├───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 25, 0, "│                   │                   │                   │");
    mvwprintw(base_atk_table_window, 26, 0, "├───────────────────┼───────────────────┼───────────────────┤");
    mvwprintw(base_atk_table_window, 27, 0, "│                   │                   │                   │");
    mvwprintw(base_atk_table_window, 28, 0, "└───────────────────┴───────────────────┴───────────────────┘");

    wrefresh(base_atk_table_window);
    return base_atk_table_window;
}

WINDOW *addSpecialAttackTable(WINDOW *&main_window)
{
    WINDOW *spec_atk_table_window = derwin(main_window, 29, 127, 4, 2);
    mvwprintw(spec_atk_table_window, 0, 0, "┌────────────────────┬────────────────────┬────────────────────┬────────────────────┬────────────────────┬────────────────────┐");
    mvwprintw(spec_atk_table_window, 1, 0, "│                    │                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 2, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 3, 0, "│                    │                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 4, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┘");
    mvwprintw(spec_atk_table_window, 5, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 6, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 7, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 8, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 9, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 10, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 11, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 12, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 13, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 14, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 15, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 16, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 17, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 18, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 19, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 20, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 21, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 22, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 23, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 24, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 25, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 26, 0, "├────────────────────┼────────────────────┼────────────────────┼────────────────────┼────────────────────┤");
    mvwprintw(spec_atk_table_window, 27, 0, "│                    │                    │                    │                    │                    │");
    mvwprintw(spec_atk_table_window, 28, 0, "└────────────────────┴────────────────────┴────────────────────┴────────────────────┴────────────────────┘");

    wrefresh(spec_atk_table_window);
    return spec_atk_table_window;
}
void writeAttacksToTable([[maybe_unused]] WINDOW *&atk_table_window, std::vector<Attack> &attacks)
{
    int xpos = 2;
    int ypos = 1;

    int y_offset = 2;
    int x_offset;
    bool special_flag;
    if (attacks.size() == 51) // base_attacks
    {
        special_flag = false;
        x_offset = 20;
    }
    else // spec_attacks (size == 72)
    {
        special_flag = true;
        x_offset = 21;
    }
    int attack_count = 0;

    for (Attack attack : attacks)
    {
        // size_t name_offset = attack.getName().size();
        wattron(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType())));
        mvwprintw(atk_table_window, ypos, xpos, " %s", attack.getName().c_str());
        wattroff(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType())));

        mvwprintw(atk_table_window, ypos, xpos + 14, (special_flag) ? "%3d" : "%2d", attack.getPower());
        ypos += y_offset;
        if (attack_count != 13)
        {
            attack_count++;
        }
        else
        {
            attack_count = 0;
            xpos += x_offset;
            ypos = 1;
        }
    }
    wrefresh(atk_table_window);
}
void highlightAttackInTable([[maybe_unused]] WINDOW *&atk_table_window, std::vector<Attack> &attacks, int &attack_input_index, bool highlight_flag)
{
    Attack attack = attacks.at(static_cast<unsigned long>(attack_input_index));

    int xpos = 2;
    int ypos = 1;

    int x_offset;
    bool special_flag;
    if (attacks.size() == 51) // base_attacks
    {
        special_flag = false;
        x_offset = 20;
    }
    else // spec_attacks (size == 72)
    {
        special_flag = true;
        x_offset = 21;
    }

    [[maybe_unused]] int space_amount = x_offset - static_cast<int>(attack.getName().size()) - 4;
    if (highlight_flag)
        space_amount -= 2;
    // size_t name_offset = attack.getName().size();
    (highlight_flag) ? wattron(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType()) + 20)) : wattron(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType())));
    mvwprintw(atk_table_window, (attack_input_index % 14) * 2 + ypos, (attack_input_index / 14) * x_offset + xpos, " %s", attack.getName().c_str());
    (highlight_flag) ? wattron(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType()) + 20)) : wattroff(atk_table_window, COLOR_PAIR(static_cast<short>(attack.getType())));

    for (int i = 0; i != space_amount; i++)
        wprintw(atk_table_window, " ");
    if (highlight_flag)
        wattron(atk_table_window, COLOR_PAIR(static_cast<short>(Type::Normal) + 20));
    // mvwprintw(atk_table_window, (attack_input_index%14)*2+ypos, (attack_input_index/14)*x_offset+xpos+14, "%s", std::to_string(attack.getPower()).c_str());
    mvwprintw(atk_table_window, (attack_input_index % 14) * 2 + ypos, (attack_input_index / 14) * x_offset + xpos + 14, (special_flag) ? "%3d " : "%2d ", attack.getPower());
    if (highlight_flag)
        wattroff(atk_table_window, COLOR_PAIR(static_cast<short>(Type::Normal) + 20));
    wrefresh(atk_table_window);
}
InventoryPokemon addInventoryPokemon(WINDOW *&main_window, std::vector<PokedexPokemon> &pokedex, std::vector<Attack> base_attacks, std::vector<Attack> special_attacks)
{
    PokemonWindow temporary_pokemon_window = PokemonWindow(main_window, 13, 109);
    fillInventoryPokemonWindow(temporary_pokemon_window.complete_pokemon_window);

#if 1 // Name/Type Pick
    [[maybe_unused]] PokedexPokemon chosen_pokedex_pokemon = PokedexPokemon(1,"hello", Type::Normal, Type::Normal, 0, 0, 0, "world");
    [[maybe_unused]] int return_index;
    [[maybe_unused]] std::string return_name;
    [[maybe_unused]] Type return_type_1;
    [[maybe_unused]] Type return_type_2;
    {
        int ch;
        WINDOW *temporary_pokedex_table_window = derwin(main_window, 23, 91, 7, 8);
        fillPokedexWindow(temporary_pokedex_table_window);

        WINDOW *move_buttons = drawMoveButtons(main_window, 31, 97);
        WINDOW *continue_button = drawContinueButton(main_window, 31, 122);
        int x = 0, y = 0;
        switchHighlight(temporary_pokedex_table_window, 0, 0, 1);

        addRefreshNameAndType(temporary_pokemon_window.name_window, temporary_pokemon_window.type_window, pokedex, x, y);

        while ((ch = getch()) != '\n')
        {
            // /*RESIZE CHECK*/
            // if (ch == KEY_RESIZE)
            // {
            //     if (isWindowTooSmallPokedex())
            //     {
            //         window_too_small = true;
            //         displayResizeMessagePokedex();
            //     }
            //     else if (window_too_small) // window isn't too small, but the flag is still true
            //     {
            //         window_too_small = false;
            //         resizeWindowsFix(main_window, temporary_pokedex_table_window, pokedex_info,
            //                          index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win);
            //         switchHighlight(temporary_pokedex_table_window, y, x, 1);
            //         refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            //     }
            //     else
            //     {
            //         resizeWindowsFix(main_window, temporary_pokedex_table_window, pokedex_info,
            //                          index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win);
            //         switchHighlight(temporary_pokedex_table_window, y, x, 1);
            //         refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            //     }
            //     continue;
            // }

            // if (window_too_small)
            // {
            //     continue; // ignore input while the window is too small
            // }

            switch (ch)
            {
            case KEY_UP:
                switchHighlight(temporary_pokedex_table_window, y, x, 0);
                if (y > 0)
                    y--;
                else
                {
                    y = (x == 0) ? (y = 10) : (y = 9);
                }
                switchHighlight(temporary_pokedex_table_window, y, x, 1);
                addRefreshNameAndType(temporary_pokemon_window.name_window, temporary_pokemon_window.type_window, pokedex, x, y);
                break;
            case KEY_DOWN:
                switchHighlight(temporary_pokedex_table_window, y, x, 0);
                if (y < 9)
                {
                    y++;
                }
                else
                {
                    if (y == 9)
                        y = (x == 0) ? y + 1 : y = 0;
                    else
                        y = 0;
                }
                switchHighlight(temporary_pokedex_table_window, y, x, 1);
                addRefreshNameAndType(temporary_pokemon_window.name_window, temporary_pokemon_window.type_window, pokedex, x, y);
                break;
            case KEY_LEFT:
                if (y == 10)
                {
                }
                else
                {

                    switchHighlight(temporary_pokedex_table_window, y, x, 0);
                    x = (x > 0) ? x - 1 : 14;
                    switchHighlight(temporary_pokedex_table_window, y, x, 1);
                }
                addRefreshNameAndType(temporary_pokemon_window.name_window, temporary_pokemon_window.type_window, pokedex, x, y);
                break;
            case KEY_RIGHT:
                if (y == 10)
                {
                }
                else
                {
                    switchHighlight(temporary_pokedex_table_window, y, x, 0);
                    x = (x < 14) ? x + 1 : 0;
                    switchHighlight(temporary_pokedex_table_window, y, x, 1);
                }
                addRefreshNameAndType(temporary_pokemon_window.name_window, temporary_pokemon_window.type_window, pokedex, x, y);
                break;
            default:
                break;
            }
        }
        clearWindow(temporary_pokedex_table_window);
        clearWindow(move_buttons);
        clearWindow(continue_button);
        chosen_pokedex_pokemon = pokedex.at(static_cast<unsigned long>(y * 15 + x));
        return_index = chosen_pokedex_pokemon.getIndex();
        return_name = chosen_pokedex_pokemon.getName();
        return_type_1 = chosen_pokedex_pokemon.getType().first;
        return_type_2 = chosen_pokedex_pokemon.getType().second;
    }

#endif

#if 1 // weightOrHeight pick
    [[maybe_unused]] float return_weight;
    [[maybe_unused]] float return_height;
    {
        return_weight = weightOrHeightSelect(main_window, chosen_pokedex_pokemon,"weight");
        mvwprintw(temporary_pokemon_window.weight_window, 0, (19 - static_cast<int>((returnWithRightPrecision(return_weight)).size()) - 7 - 2) / 2, "Weight: %skg", returnWithRightPrecision(return_weight).c_str());
        wrefresh(temporary_pokemon_window.weight_window);

        return_height = weightOrHeightSelect(main_window, chosen_pokedex_pokemon,"height");
        mvwprintw(temporary_pokemon_window.height_window, 0, (18 - static_cast<int>((returnWithRightPrecision(return_height)).size()) - 7 - 1) / 2, "Height: %sm", returnWithRightPrecision(return_height).c_str());
        wrefresh(temporary_pokemon_window.height_window);
    }

#endif

#if 1 // hpCpDefence pick
    [[maybe_unused]] int return_HP;
    [[maybe_unused]] int return_CP;
    [[maybe_unused]] int return_defence;
    {
        return_HP = hpCpDefSelect(main_window, "HP");
        mvwprintw(temporary_pokemon_window.hp_window, 0, (10 - static_cast<int>(std::to_string(return_HP).size()) - 4) / 2, "HP: %s", std::to_string(return_HP).c_str());
        wrefresh(temporary_pokemon_window.hp_window);

        return_CP = hpCpDefSelect(main_window, "CP");
        mvwprintw(temporary_pokemon_window.cp_window, 0, (11 - static_cast<int>(std::to_string(return_CP).size()) - 4) / 2, "CP: %s", std::to_string(return_CP).c_str());
        wrefresh(temporary_pokemon_window.cp_window);

        return_defence = hpCpDefSelect(main_window, "Def");
        mvwprintw(temporary_pokemon_window.defence_window, 0, (15 - static_cast<int>(std::to_string(return_defence).size()) - 9) / 2, "Defence: %s", std::to_string(return_defence).c_str());
        wrefresh(temporary_pokemon_window.defence_window);
    }
#endif

#if 1 // Base attack pick
    [[maybe_unused]] Attack return_base_attack = Attack("hello", Type::Normal, 404);
    {

        WINDOW *atk_window = addBaseAttackTable(main_window);

        WINDOW *move_buttons = drawMoveButtons(main_window, 31, 97);
        WINDOW *continue_button = drawContinueButton(main_window, 31, 122);

        writeAttacksToTable(atk_window, base_attacks);
        int ch;
        int attack_input_index = 0;
        highlightAttackInTable(atk_window, base_attacks, attack_input_index, 1);
        wclear(temporary_pokemon_window.base_atk_window);
        wclear(temporary_pokemon_window.base_atk_power_window);
        writingOutAttack(temporary_pokemon_window.base_atk_window, temporary_pokemon_window.base_atk_power_window, base_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
        wrefresh(temporary_pokemon_window.base_atk_window);
        wrefresh(temporary_pokemon_window.base_atk_power_window);
        while ((ch = getch()) != '\n')
        {

            switch (ch)
            {
            case KEY_UP:
                if (attack_input_index % 14 == 0)
                {
                } // we are at the top;
                else
                {
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 0);
                    attack_input_index--;
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.base_atk_window);
                    wclear(temporary_pokemon_window.base_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.base_atk_window, temporary_pokemon_window.base_atk_power_window, base_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.base_atk_window);
                    wrefresh(temporary_pokemon_window.base_atk_power_window);
                }
                break;
            case KEY_DOWN:
                if ((((attack_input_index - 13) % 14 == 0) && (attack_input_index - 13) / 14 + 1 > 0) || attack_input_index == 50)
                {
                } // we are at the bottom or the right column's bottom;
                else
                {
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 0);
                    attack_input_index++;
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.base_atk_window);
                    wclear(temporary_pokemon_window.base_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.base_atk_window, temporary_pokemon_window.base_atk_power_window, base_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.base_atk_window);
                    wrefresh(temporary_pokemon_window.base_atk_power_window);
                }
                break;
            case KEY_LEFT:
                if (attack_input_index < 14)
                {
                } // we are at the left wall;
                else
                {
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 0);
                    attack_input_index -= 14;
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.base_atk_window);
                    wclear(temporary_pokemon_window.base_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.base_atk_window, temporary_pokemon_window.base_atk_power_window, base_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.base_atk_window);
                    wrefresh(temporary_pokemon_window.base_atk_power_window);
                }
                break;
            case KEY_RIGHT:
                if (attack_input_index > 36)
                {
                } // we are at the right wall;
                else
                {
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 0);
                    attack_input_index += 14;
                    highlightAttackInTable(atk_window, base_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.base_atk_window);
                    wclear(temporary_pokemon_window.base_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.base_atk_window, temporary_pokemon_window.base_atk_power_window, base_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.base_atk_window);
                    wrefresh(temporary_pokemon_window.base_atk_power_window);
                }
            default:
                break;
            }
        }
        return_base_attack = base_attacks.at(static_cast<unsigned long>(attack_input_index));
        clearWindow(move_buttons);
        clearWindow(continue_button);
    }
#endif

#if 1 // Special attack pick
    [[maybe_unused]] Attack return_special_attack = Attack("hello", Type::Normal, 404);
    {
        WINDOW *atk_window = addSpecialAttackTable(main_window);

        WINDOW *move_buttons = drawMoveButtons(main_window, 28, 114);
        WINDOW *complete_pokemon_button = drawCompletePokemonButton(main_window, 31, 122);

        writeAttacksToTable(atk_window, special_attacks);
        int ch;
        int attack_input_index = 0;
        highlightAttackInTable(atk_window, special_attacks, attack_input_index, 1);
        wclear(temporary_pokemon_window.spec_atk_window);
        wclear(temporary_pokemon_window.spec_atk_power_window);
        writingOutAttack(temporary_pokemon_window.spec_atk_window, temporary_pokemon_window.spec_atk_power_window, special_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
        wrefresh(temporary_pokemon_window.spec_atk_window);
        wrefresh(temporary_pokemon_window.spec_atk_power_window);
        [[maybe_unused]] int special_attacks_size = static_cast<int>(special_attacks.size());
        while ((ch = getch()) != '\n')
        {

            switch (ch)
            {
            case KEY_UP:
                if (attack_input_index % 14 == 0)
                {
                } // we are at the top;
                else
                {
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 0);
                    attack_input_index--;
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.spec_atk_window);
                    wclear(temporary_pokemon_window.spec_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.spec_atk_window, temporary_pokemon_window.spec_atk_power_window, special_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.spec_atk_window);
                    wrefresh(temporary_pokemon_window.spec_atk_power_window);
                }
                break;
            case KEY_DOWN:
                if ((((attack_input_index - 13) % 14 == 0) && (attack_input_index - 13) / 14 + 1 > 0) || attack_input_index == 71)
                {
                } // we are at the bottom or the right column's bottom;
                else
                {
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 0);
                    attack_input_index++;
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.spec_atk_window);
                    wclear(temporary_pokemon_window.spec_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.spec_atk_window, temporary_pokemon_window.spec_atk_power_window, special_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.spec_atk_window);
                    wrefresh(temporary_pokemon_window.spec_atk_power_window);
                }
                break;
            case KEY_LEFT:
                if (attack_input_index < 14)
                {
                } // we are at the left wall;
                else
                {
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 0);
                    attack_input_index -= 14;
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.spec_atk_window);
                    wclear(temporary_pokemon_window.spec_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.spec_atk_window, temporary_pokemon_window.spec_atk_power_window, special_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.spec_atk_window);
                    wrefresh(temporary_pokemon_window.spec_atk_power_window);
                }
                break;
            case KEY_RIGHT:
                if (attack_input_index > 57)
                {
                } // we are at the right wall;
                else
                {
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 0);
                    attack_input_index += 14;
                    highlightAttackInTable(atk_window, special_attacks, attack_input_index, 1);
                    wclear(temporary_pokemon_window.spec_atk_window);
                    wclear(temporary_pokemon_window.spec_atk_power_window);
                    writingOutAttack(temporary_pokemon_window.spec_atk_window, temporary_pokemon_window.spec_atk_power_window, special_attacks.at(static_cast<unsigned long>(attack_input_index)), return_type_1, return_type_2, 0);
                    wrefresh(temporary_pokemon_window.spec_atk_window);
                    wrefresh(temporary_pokemon_window.spec_atk_power_window);
                }
            default:
                break;
            }
        }
        return_special_attack = special_attacks.at(static_cast<unsigned long>(attack_input_index));
        clearWindow(move_buttons);
        clearWindow(complete_pokemon_button);
    }
#endif

    wclear(main_window);
    box(main_window, 0, 0);
    wrefresh(main_window);
    return InventoryPokemon(return_index, return_name, return_type_1, return_type_2, return_weight, return_height, return_HP, return_CP, return_defence, return_base_attack, return_special_attack);
}

void writeInventoryToFile(const std::string &filename, const std::vector<InventoryPokemon> &inventory)
{
    std::ofstream file(filename);

    for (InventoryPokemon pokemon : inventory)
    {
        file << std::to_string(pokemon.getIndex()) << ", "
             << pokemon.getName() << ", "
             << TypeTtoS(pokemon.getType().first) << ", "
             << TypeTtoS(pokemon.getType().second) << ", "
             << returnWithRightPrecision(pokemon.getWeight()) << ", "
             << returnWithRightPrecision(pokemon.getHeight()) << ", "
             << std::to_string(pokemon.getHP()) << ", "
             << std::to_string(pokemon.getCP()) << ", "
             << std::to_string(pokemon.getDefence()) << ", "
             << pokemon.getBaseAttack().getName() << ", "
             << TypeTtoS(pokemon.getBaseAttack().getType()) << ", "
             << std::to_string(pokemon.getBaseAttack().getPower()) << ", "
             << pokemon.getSpecialAttack().getName() << ", "
             << TypeTtoS(pokemon.getSpecialAttack().getType()) << ", "
             << std::to_string(pokemon.getSpecialAttack().getPower()) << "\n";
    }
    file.close();
}
void mainInventory()
{
    setlocale(LC_ALL, "");
    {
        initscr();
        refresh();
    }
    noecho();
    curs_set(FALSE);      // no cursor
    keypad(stdscr, true); // arrows+function keys on
    start_color();
    // init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
#define SETUP
#ifdef SETUP
#if 1
    std::vector<PokedexPokemon> pokedex;
    fillPokedex("pokedex.txt", pokedex);
#endif
#define COLOR_SETUP
#ifdef COLOR_IS_NOT_DEFINED_HERE
    init_pair(static_cast<short>(Type::Normal), COLOR_WHITE, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Fire), 196, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Water), 4, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Electric), 3, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Grass), 34, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Ice), 81, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Fighting), 1, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Poison), 165, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Ground), 130, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Flying), 153, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Psychic), 207, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Bug), 106, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Rock), 142, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Ghost), 57, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Dragon), 33, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Dark), 247, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Steel), 252, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Fairy), 219, COLOR_BLACK);

    init_pair(static_cast<short>(Type::Normal) + 20, COLOR_BLACK, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Fire) + 20, 196, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Water) + 20, 4, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Electric) + 20, 3, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Grass) + 20, 34, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Ice) + 20, COLOR_BLACK, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Fighting) + 20, 1, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Poison) + 20, 165, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Ground) + 20, 130, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Flying) + 20, COLOR_BLACK, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Psychic) + 20, 207, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Bug) + 20, 106, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Rock) + 20, 142, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Ghost) + 20, 57, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Dragon) + 20, 33, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Dark) + 20, 247, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Steel) + 20, COLOR_BLACK, COLOR_WHITE);
    init_pair(static_cast<short>(Type::Fairy) + 20, 219, COLOR_WHITE);
#endif
    std::vector<Attack> base_attacks;
    std::vector<Attack> special_attacks;
    fillAttacks("attacks.txt", base_attacks, special_attacks);

    std::vector<InventoryPokemon> inventory;
    fillInventory("inventory.txt", inventory);
    [[maybe_unused]] int input_index = 0;

    WINDOW *main_window = newwin(37, 152, 0, 0);
    box(main_window, 0, 0);
    wrefresh(main_window);

    drawInfoPanelInventory(main_window);

    WINDOW *pokemon_count_window = derwin(main_window, 3, 9, 31, 133);
    drawHighlightPokemonCount(pokemon_count_window, input_index, static_cast<int>(inventory.size()));

    std::vector<PokemonWindow> pokemon_windows;
    pushingPokemonWindows(main_window, pokemon_windows);
    // // mvwprintw(main_window,1,1, "The size of pokedex is %d", pokemon_windows.size());
    // // wrefresh(main_window);

    refreshInventoryFull(pokemon_windows, inventory, input_index);
#endif

#if 1
    int ch;
    bool window_too_small = false;

    while ((ch = getch()) != 'b')
    {
        // wclear(in_development_window);
        // wrefresh(in_development_window);
        /*RESIZE CHECK*/
        if (ch == KEY_RESIZE)
        {
            // fflush(stdin);
            if (isWindowTooSmall())
            {
                window_too_small = true;
                displayResizeMessage();
            }
            else if (window_too_small) // window isn't too small, but the flag is still true
            {
                window_too_small = false;
                resizeWindowsFix(main_window, pokemon_windows, pokemon_count_window, inventory, input_index);
            }
            else
            {
                resizeWindowsFix(main_window, pokemon_windows, pokemon_count_window, inventory, input_index);
            }
            continue;
        }

        if (window_too_small)
        {
            continue; // ignore input while the window is too small
        }

        switch (ch)
        {
        case 'a':
            wclear(main_window);
            box(main_window, 0, 0);
            wrefresh(main_window);
            inventory.push_back(addInventoryPokemon(main_window, pokedex, base_attacks, special_attacks));
            input_index = static_cast<int>(inventory.size()) - 1;
            resizeWindowsFix(main_window, pokemon_windows, pokemon_count_window, inventory, input_index);
            drawInfoPanelInventory(main_window);
            refreshInventoryFull(pokemon_windows, inventory, input_index);
            break;
        case 'd':
            deleteConfirmation(main_window, inventory, input_index);
            resizeWindowsFix(main_window, pokemon_windows, pokemon_count_window, inventory, input_index);
            drawInfoPanelInventory(main_window);
            refreshInventoryFull(pokemon_windows, inventory, input_index);
            break;
        case KEY_UP:
            if ((input_index % 6) > 2)
            {
                refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 0);
                input_index -= 3;
                refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 1);
            }
            break;
        case KEY_DOWN:
            if ((input_index % 6) < 3)
            {
                if (static_cast<int>(inventory.size()) >= input_index + 1 + 3) //+1 because input_index is zero indexed, +3 because index would change by 3 after changing highlight
                {

                    refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 0);
                    input_index += 3;
                    refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 1);
                }
            }
            break;
        case KEY_LEFT:
            if ((input_index % 3) == 0) // highlighted pokemon is in the left column
            {
                if (input_index != 0 && input_index != 3) // this is not the first or fourth pokemon; else do nothing
                {
                    input_index -= 4;
                    refreshInventoryFull(pokemon_windows, inventory, input_index);
                }
            }
            else // highlighted pokemon is in the center or right column
            {
                refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 0);
                input_index--;
                refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 1);
            }
            break;
        case KEY_RIGHT:
            if ((input_index % 3) == 2) // highlighted pokemon is in the right column
            {
                if (static_cast<int>(inventory.size()) > input_index + 1) // there are more pokemon available for drawing out after refreshing the window
                {
                    if ((input_index % 6) == 5) // highlight is in the lower right corner
                    {
                        if (static_cast<int>(inventory.size()) > input_index + 1 + 3) // enough pokemon to highlight the lower left corner on the next page
                        {
                            input_index += 4;
                            refreshInventoryFull(pokemon_windows, inventory, input_index);
                        }
                        else
                        {
                            input_index++;
                            refreshInventoryFull(pokemon_windows, inventory, input_index);
                        }
                    }
                    else if ((input_index % 6) == 2) // highlight is in the upper right corner
                    {
                        if (static_cast<int>(inventory.size()) > input_index + 1 + 3)
                        {
                            input_index += 4;
                            refreshInventoryFull(pokemon_windows, inventory, input_index);
                        }
                    }
                }
            }
            else // highlighted pokemon is in the left or center column
            {
                if (static_cast<int>(inventory.size()) > input_index + 1) // there are more pokemon to the right
                {
                    refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 0);
                    input_index++;
                    refreshInventoryPokemonWindow(pokemon_windows.at(static_cast<unsigned long>(input_index % 6)), inventory, input_index, 1);
                }
            }
            break;
        default:
            break;
        }
        drawHighlightPokemonCount(pokemon_count_window, input_index, static_cast<int>(inventory.size()));
    }
#endif
    writeInventoryToFile("inventory.txt", inventory);
    wclear(main_window);
    wrefresh(main_window);
    return;
}
