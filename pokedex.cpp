#pragma once

#include "pokemon.hpp"
#include "pokemon.cpp"
#include <iostream>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h> // For usleep

WINDOW *drawMoveButtons(WINDOW *&main_window, int y, int x)
{
    WINDOW *move_window = derwin(main_window, 3, 22, y, x);

    const char *up_arrow = "\u2191";
    const char *down_arrow = "\u2193";
    const char *left_arrow = "\u2190";
    const char *right_arrow = "\u2192";

    mvwprintw(move_window, 0, 0, "┌───┬───┬───┬───┐");
    mvwprintw(move_window, 1, 0, "│ %s │ %s │ %s │ %s │ Move", up_arrow, down_arrow, left_arrow, right_arrow);
    mvwprintw(move_window, 2, 0, "└───┴───┴───┴───┘");
    wrefresh(move_window);
    return move_window;
}
WINDOW *drawBackButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *back_window = derwin(main_window, 3, 10, y, x);
    mvwprintw(back_window, 0, 0, "┌───┐");
    mvwprintw(back_window, 1, 0, "│ B │ Back");
    mvwprintw(back_window, 2, 0, "└───┘");
    wrefresh(back_window);
    return back_window;
}
void fillPokedexWindow(WINDOW *&pokedex_window)
{
    mvwprintw(pokedex_window, 0, 0, "┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐");
    mvwprintw(pokedex_window, 1, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 2, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 3, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 4, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 5, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 6, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 7, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 8, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 9, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 10, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 11, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 12, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 13, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 14, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 15, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 16, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 17, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 18, 0, "├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤");
    mvwprintw(pokedex_window, 19, 0, "│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │");
    mvwprintw(pokedex_window, 20, 0, "├─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘");
    mvwprintw(pokedex_window, 21, 0, "│     │");
    mvwprintw(pokedex_window, 22, 0, "└─────┘");
    wrefresh(pokedex_window);

    // printing pokemon numbers from 1-150
    for (int i = 0; i != 10; i++)
    {
        for (int j = 0; j != 16; j++)
        {
            mvwprintw(pokedex_window, 1 + (2 * i), 2 + (6 * j), "%03d", 1 + i * 15 + j);
        }
    }
    mvwprintw(pokedex_window, 21, 2, "%03d", 151); // 151
    wrefresh(pokedex_window);
}

void switchHighlight(WINDOW *&pokedex_window, int y, int x, int highlightFlag)
{
    if (highlightFlag)
        wattron(pokedex_window, A_REVERSE);
    mvwprintw(pokedex_window, 1 + (2 * y), 2 + (6 * x), "%03d", 1 + 15 * y + x);
    if (highlightFlag)
        wattroff(pokedex_window, A_REVERSE);
    wrefresh(pokedex_window);
}

void fillPokedexPokemonWindow(WINDOW *&pokedex_info)
{
    mvwprintw(pokedex_info, 0, 0, "┌─────┬────────────┬─────────────────────────┐");
    mvwprintw(pokedex_info, 1, 0, "│     │            │                         │");
    mvwprintw(pokedex_info, 2, 0, "├─────┴────────────┴──┬──────────────────────┤");
    mvwprintw(pokedex_info, 3, 0, "│                     │                      │");
    mvwprintw(pokedex_info, 4, 0, "├─────────────────────┴──────────────────────┤");
    mvwprintw(pokedex_info, 5, 0, "│                                            │");
    mvwprintw(pokedex_info, 6, 0, "├────────────────────────────────────────────┤");
    mvwprintw(pokedex_info, 7, 0, "│                                            │");
    mvwprintw(pokedex_info, 8, 0, "│                                            │");
    mvwprintw(pokedex_info, 9, 0, "│                                            │");
    mvwprintw(pokedex_info, 10, 0, "│                                            │");
    mvwprintw(pokedex_info, 11, 0, "│                                            │");
    mvwprintw(pokedex_info, 12, 0, "└────────────────────────────────────────────┘");
    wrefresh(pokedex_info);
}

std::string buildingEvoTree(const std::vector<PokedexPokemon> &pokedex, int input_index) // recursive function
{
    if (input_index == 134 || input_index == 135 || input_index == 136)
        return "Eevee->" + pokedex.at(static_cast<size_t>(--input_index)).getName(); // Vaporeon(133->132)/Jolteon(134->133)/Flareon(135->134)   (vector is indexed from 0)

    if (pokedex.at(static_cast<size_t>(--input_index)).baseEvoCheck())
    {
        return pokedex.at(static_cast<size_t>(input_index)).getName();
    }
    else
    {
        return buildingEvoTree(pokedex, input_index) + "->" + pokedex.at(static_cast<size_t>(input_index)).getName();
    }
}

std::string EvoTree(const std::vector<PokedexPokemon> &pokedex, const PokedexPokemon &examined_pokemon, int &input_index)
{
    /*
    TRY TO REWORK IT
    try to compare with the next pokemon in the pokedex
    if there is one, the pokemon has no evo
    if there is zero, the pokemon is the base pokemon
    for mew make an exception since it's the last pokemon in the pokedex
    */
    std::string returnString;
    if (examined_pokemon.baseEvoCheck()) // Pokemon is either base or doesn't have evolutions
    {
        if (examined_pokemon.getIndex() == 151)
            returnString = examined_pokemon.getName() + " (No evo)";                  // Pokemon is Mew
        else if (pokedex.at(static_cast<size_t>(input_index)).baseEvoCheck()) // don't need to add +1 to input_index, since vector is indexed from 1.
            returnString = examined_pokemon.getName() + " (No evo)";                  // Next pokemon is either base evo or doesn't have evolutions
        else
            returnString = examined_pokemon.getName() + " (Base evo)"; // Next pokemon is the next evolution stage of examined pokemon
    }
    else // Pokemon is some evolution
    {
        returnString = buildingEvoTree(pokedex, input_index);
    }
    return "Evo tree: " + returnString;
}

std::string returnWithRightPrecision(float attribute)
{
    std::ostringstream out;
    out << std::fixed << std::setprecision(1) << attribute;
    return out.str();
}

std::vector<std::string> prepareForPassing(const std::vector<PokedexPokemon> &pokedex, int &input_index)
{
    std::vector<std::string> pass_vector;
    PokedexPokemon examined_pokemon = pokedex.at(static_cast<size_t>(input_index - 1));

    // pass_vector.push_back(std::to_string(examined_pokemon.getIndex())); // we don't need to find out the index; we can use input_index
    pass_vector.push_back(examined_pokemon.getName());
    // pass_vector.push_back(TypeTtoS(examined_pokemon.getType().first) + "/" + TypeTtoS(examined_pokemon.getType().second));

    pass_vector.push_back("avg. Weight: "+ returnWithRightPrecision(examined_pokemon.getAvgWeight()));
    pass_vector.push_back("avg. Height: "+ returnWithRightPrecision(examined_pokemon.getAvgHeight()));

    pass_vector.push_back(EvoTree(pokedex, examined_pokemon, input_index));

    pass_vector.push_back(examined_pokemon.getFlavorText());
    return pass_vector;
}


void writingOutType(WINDOW *&type_win, Type type1, Type type2)
{
    
    // specific colours
    // init_pair(static_cast<short>(Type::Normal), COLOR_WHITE, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Fire), 196, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Water), 4, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Electric), 3, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Grass), 34, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Ice), 81, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Fighting), 1, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Poison), 165, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Ground), 130, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Flying), 153, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Psychic), 207, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Bug), 106, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Rock), 142, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Ghost), 57, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Dragon), 33, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Dark), 247, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Steel), 252, COLOR_BLACK);
    // init_pair(static_cast<short>(Type::Fairy), 219, COLOR_BLACK);
    


    size_t offset;
    if (type2 == Type::None)
    {
        offset = TypeTtoS(type1).size();
    }
    else
    {
        offset = TypeTtoS(type1).size()+TypeTtoS(type2).size()+1;
    }


    wattron(type_win, COLOR_PAIR(static_cast<short>(type1)));
    mvwprintw(type_win,0, (23 - static_cast<int>(offset))/2, "%s", TypeTtoS(type1).c_str());
    wattroff(type_win, COLOR_PAIR(static_cast<short>(type1)));

    if (type2 != Type::None)
    {
        wprintw(type_win, "/");
        wattron(type_win, COLOR_PAIR(static_cast<short>(type2)));
        wprintw(type_win, "%s", TypeTtoS(type2).c_str());
        wattroff(type_win, COLOR_PAIR(static_cast<short>(type2)));
    }
}


void refreshPokedexPokemonWindow(WINDOW *&index_win, WINDOW *&name_win, WINDOW *&type_win, WINDOW *&avgWeight_win, WINDOW *&avgHeight_win, WINDOW *&evoTree_win, WINDOW *&flavorText_win,
                                 const std::vector<PokedexPokemon> &pokedex, int &input_index)
{
    wclear(index_win);
    wclear(name_win);
    wclear(type_win);
    wclear(avgWeight_win);
    wclear(avgHeight_win);
    wclear(evoTree_win);
    wclear(flavorText_win);
    std::vector<std::string> pass_vector = prepareForPassing(pokedex, input_index);

#if 0 // debug
    for (size_t i = 0; i < pass_vector.size(); i++)
    {
        mvprintw(static_cast<int>(i),0, "%s",pass_vector.at(i).c_str());
    }
#endif
#if 1
    mvwprintw(index_win, 0, (5 - 3) / 2, "%03d", input_index);
    wrefresh(index_win);

    // wbkgd(name_win, COLOR_PAIR(2));
    // wattron(name_win, A_REVERSE);
    mvwprintw(name_win, 0, (10 - static_cast<int>(pass_vector.at(0).size())) / 2, "%s", pass_vector.at(0).c_str());
    wrefresh(name_win);

    // wbkgd(type_win, COLOR_PAIR(1));
    // wattron(type_win, A_REVERSE);
    // mvwprintw(type_win, 0, (23 - static_cast<int>(pass_vector.at(1).size())) / 2, "%s", pass_vector.at(1).c_str());
    writingOutType(type_win, pokedex.at(static_cast<size_t>(input_index - 1)).getType().first, pokedex.at(static_cast<size_t>(input_index - 1)).getType().second);
    wrefresh(type_win);

    // wbkgd(avgWeight_win, COLOR_PAIR(1));
    // wattron(avgWeight_win, A_REVERSE);
    mvwprintw(avgWeight_win, 0, (19 - static_cast<int>(pass_vector.at(1).size())) / 2, "%s", pass_vector.at(1).c_str());
    wrefresh(avgWeight_win);

    // wbkgd(avgHeight_win, COLOR_PAIR(1));
    // wattron(avgHeight_win, A_REVERSE);
    mvwprintw(avgHeight_win, 0, (20 - static_cast<int>(pass_vector.at(2).size())) / 2, "%s", pass_vector.at(2).c_str());
    wrefresh(avgHeight_win);

    // wbkgd(evoTree_win, COLOR_PAIR(1));
    // wattron(evoTree_win, A_REVERSE);
    mvwprintw(evoTree_win, 0, (42 - static_cast<int>(pass_vector.at(3).size())) / 2, "%s", pass_vector.at(3).c_str());
    wrefresh(evoTree_win);

    // wbkgd(flavorText_win, COLOR_PAIR(1));
    // wattron(flavorText_win, A_REVERSE);
    mvwprintw(flavorText_win, 1, 0, "%s", pass_vector.at(4).c_str());
    wrefresh(flavorText_win);
#endif
}

bool isWindowTooSmall()
{
    return (LINES < 40 || COLS < 155);
}
void displayResizeMessage()
{
    clear();
    mvwprintw(stdscr, LINES / 2, (COLS - 25) / 2, "Expand window to continue");
    refresh();
}

void resizeWindowsFix(WINDOW *&main_window, WINDOW *&pokedex_window, WINDOW *&pokedex_info,
                      WINDOW *&index_win, WINDOW *&name_win, WINDOW *&type_win, WINDOW *&avgWeight_win, WINDOW *&avgHeight_win, WINDOW *&evoTree_win, WINDOW *&flavorText_win)
{
    clear();
    refresh();
    wresize(main_window, 37, 152);
    mvwin(main_window, 0, 0);
    wclear(main_window);
    box(main_window, 0, 0);
    wrefresh(main_window);

    /*subwindows of main_window*/
    wresize(pokedex_window, 23, 91);
    mvwin(pokedex_window, 7, 4);
    fillPokedexWindow(pokedex_window);

    wresize(pokedex_info, 13, 46);
    mvwin(pokedex_info, 10, 101);
    fillPokedexPokemonWindow(pokedex_info);

    /*subwindows of pokedex_info*/
    int pokedex_info_y, pokedex_info_x;
    getbegyx(pokedex_info, pokedex_info_y, pokedex_info_x);

    wresize(index_win, 1, 5);
    mvwin(index_win, pokedex_info_y + 1, pokedex_info_x + 1);
    wresize(name_win, 1, 10);
    mvwin(name_win, pokedex_info_y + 1, pokedex_info_x + 8);
    wresize(type_win, 1, 23);
    mvwin(type_win, pokedex_info_y + 1, pokedex_info_x + 21);
    wresize(avgWeight_win, 1, 19);
    mvwin(avgWeight_win, pokedex_info_y + 3, pokedex_info_x + 2);
    wresize(avgHeight_win, 1, 20);
    mvwin(avgHeight_win, pokedex_info_y + 3, pokedex_info_x + 24);
    wresize(evoTree_win, 1, 42);
    mvwin(evoTree_win, pokedex_info_y + 5, pokedex_info_x + 2);
    wresize(flavorText_win, 5, 42);
    mvwin(flavorText_win, pokedex_info_y + 7, pokedex_info_x + 2);

    drawMoveButtons(main_window, 31,105);
    drawBackButton(main_window, 31,130);
}

int mainPokedex()
{

#if 0
    for (auto it = pokedex.begin(); it != pokedex.end(); it++)
    {
        std::cout << std::setw(10) << it->getAvgWeight() << std::left << std::setw(10) << it->getName() << " " << TypeTtoS(it->getType().first) << TypeTtoS(it->getType().second) << " " << it->getIndex() << " " << it->baseEvoCheck() << std::endl;
    }
#endif

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

#ifndef SETUP
    std::vector<PokedexPokemon> pokedex;
    fillPokedex("pokedex.txt", pokedex);

    WINDOW *main_window = newwin(37, 152, 0, 0);
    box(main_window, 0, 0);
    wrefresh(main_window);

    // whole pokedex(001, 002, ...)
    WINDOW *pokedex_window = derwin(main_window, 23, 91, 7, 4);
    fillPokedexWindow(pokedex_window);
    // specific pokemon
    WINDOW *pokedex_info = derwin(main_window, 13, 46, 10, 101);
    WINDOW *index_win = derwin(pokedex_info, 1, 5, 1, 1);
    WINDOW *name_win = derwin(pokedex_info, 1, 10, 1, 8);
    WINDOW *type_win = derwin(pokedex_info, 1, 23, 1, 21);
    WINDOW *avgWeight_win = derwin(pokedex_info, 1, 19, 3, 2);
    WINDOW *avgHeight_win = derwin(pokedex_info, 1, 20, 3, 24);
    WINDOW *evoTree_win = derwin(pokedex_info, 1, 42, 5, 2);
    WINDOW *flavorText_win = derwin(pokedex_info, 5, 42, 7, 2);

    // flushing everything onto the screen
    fillPokedexPokemonWindow(pokedex_info);
    wrefresh(index_win);
    wrefresh(name_win);
    wrefresh(type_win);
    wrefresh(avgWeight_win);
    wrefresh(avgHeight_win);
    wrefresh(evoTree_win);
    wrefresh(flavorText_win);

    drawMoveButtons(main_window, 31,105);
    drawBackButton(main_window, 31,130);
#endif

    int ch;
    bool window_too_small = false;

    switchHighlight(pokedex_window, 0, 0, 1); // highlighting 001 at pokedex_window
    int input_index = 1;
    refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index); // writing Bulbasaur to the screen
    // wbkgd(pokedex_info, A_REVERSE);
    // wrefresh(pokedex_info);
    wrefresh(main_window);
    int x = 0, y = 0;

    while ((ch = getch()) != 'b')
    {
        /*RESIZE CHECK*/
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
                resizeWindowsFix(main_window, pokedex_window, pokedex_info,
                                 index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win);
                switchHighlight(pokedex_window, y, x, 1);
                refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            }
            else
            {
                resizeWindowsFix(main_window, pokedex_window, pokedex_info,
                                 index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win);
                switchHighlight(pokedex_window, y, x, 1);
                refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            }
            continue;
        }

        if (window_too_small)
        {
            continue; // ignore input while the window is too small
        }

        switch (ch)
        {
        case KEY_UP:
            switchHighlight(pokedex_window, y, x, 0);
            if (y > 0)
                y--;
            else
            {
                y = (x == 0) ? (y = 10) : (y = 9);
            }
            switchHighlight(pokedex_window, y, x, 1);
            input_index = 1 + 15 * y + x;
            refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            break;
        case KEY_DOWN:
            switchHighlight(pokedex_window, y, x, 0);
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
            switchHighlight(pokedex_window, y, x, 1);
            input_index = 1 + 15 * y + x;
            refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            break;
        case KEY_LEFT:
            if (y == 10)
            {
            }
            else
            {

                switchHighlight(pokedex_window, y, x, 0);
                x = (x > 0) ? x - 1 : 14;
                switchHighlight(pokedex_window, y, x, 1);
            }
            input_index = 1 + 15 * y + x;
            refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            break;
        case KEY_RIGHT:
            if (y == 10)
            {
            }
            else
            {
                switchHighlight(pokedex_window, y, x, 0);
                x = (x < 14) ? x + 1 : 0;
                switchHighlight(pokedex_window, y, x, 1);
            }
            input_index = 1 + 15 * y + x;
            refreshPokedexPokemonWindow(index_win, name_win, type_win, avgWeight_win, avgHeight_win, evoTree_win, flavorText_win, pokedex, input_index);
            break;
        default:
            break;
        }
    }
    wclear(main_window);
    wrefresh(main_window);
    delwin(flavorText_win);
    delwin(evoTree_win);
    delwin(avgHeight_win);
    delwin(avgWeight_win);
    delwin(type_win);
    delwin(name_win);
    delwin(index_win);
    delwin(pokedex_info);
    delwin(pokedex_window);
    delwin(main_window);
    endwin();
    return 0;
}


#if 0
 ┌─────┬────────────┬─────────────────────────┐
 │ 003 │ 1234567891 │ Type: 12345678/12345678 │
 ├─────┴────────────┴──┬──────────────────────┤
 │ 1234567891          │ henlo                │
 ├─────────────────────┴──────────────────────┤
 │ Evo tree:Dratini -> Dragonair -> Dragonite │
 ├────────────────────────────────────────────┤
 │  The plant blooms when it is absorbing sol │
 │ ar energy. It stays on the move to seek su │
 │ nlight.                                    │
 │                                            │
 │                                            │
 └────────────────────────────────────────────┘
#endif

#if 0
+---------------------------------------------+
| 003 | 1234567891 |  Type: 12345678/12345678 |
+---------------------------------------------+
|      Bulbasaur -> Ivysaur -> Venusaur       |
+---------------------------------------------+ 
|    avg.weight: 100kg   |   avg.height: 2m   |
+---------------------------------------------+ 
|    The plant blooms when it is absorbing    |
|    solar energy. It stays on the move to    |
|    seek sunlight.                           |
+---------------------------------------------+
#endif
