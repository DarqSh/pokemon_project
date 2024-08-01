#include "pokemon.hpp"
#include "pokemon.cpp"

#include "pokedex.cpp"
#include "inventory.cpp"

#include <iostream>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h> // For usleep

WINDOW *drawCondensedMoveButtons(WINDOW *&main_window, int y, int x)
{
    WINDOW *move_window = derwin(main_window, 3, 16, y, x);

    const char *up_arrow = "\u2191";
    const char *down_arrow = "\u2193";

    mvwprintw(move_window, 0, 0, "┌───┬───┐");
    mvwprintw(move_window, 1, 0, "│ %s │ %s │ Move", up_arrow, down_arrow);
    mvwprintw(move_window, 2, 0, "└───┴───┘");
    wrefresh(move_window);
    return move_window;
}
WINDOW *drawChooseButton(WINDOW *&main_window, int y, int x)
{
    WINDOW *continue_window = derwin(main_window, 3, 16, y, x);
    mvwprintw(continue_window, 0, 0, "┌───────┐");
    mvwprintw(continue_window, 1, 0, "│ Enter │ Choose");
    mvwprintw(continue_window, 2, 0, "└───────┘");
    wrefresh(continue_window);
    return continue_window;
}
void drawPokemonLogo(WINDOW *&main_window, int y, int x)
{
    wattron(main_window, COLOR_PAIR(static_cast<short>(Type::Electric)));
    mvwprintw(main_window, y++, x, "                                  ,'\\");
    mvwprintw(main_window, y++, x, "    _.----.        ____         ,'  _\\   ___    ___     ____");
    mvwprintw(main_window, y++, x, "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.");
    mvwprintw(main_window, y++, x, "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |");
    mvwprintw(main_window, y++, x, " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |");
    mvwprintw(main_window, y++, x, "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |");
    mvwprintw(main_window, y++, x, "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |");
    mvwprintw(main_window, y++, x, "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |");
    mvwprintw(main_window, y++, x, "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |");
    mvwprintw(main_window, y++, x, "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |");
    mvwprintw(main_window, y++, x, "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |");
    mvwprintw(main_window, y++, x, "                                `'                            '-._|");
    wattroff(main_window, COLOR_PAIR(static_cast<short>(Type::Electric)));
    wrefresh(main_window);
}

void redrawMenuWindow(WINDOW *&main_window, int y, int x, int &input_index)
{
    WINDOW *menu_window = derwin(main_window, 7, 21, y, x);
    mvwprintw(menu_window, 0, 0, "┌───────────────────┐");
    mvwprintw(menu_window, 1, 0, "│                   │");
    mvwprintw(menu_window, 2, 0, "├───────────────────┤");
    mvwprintw(menu_window, 3, 0, "│                   │");
    mvwprintw(menu_window, 4, 0, "├───────────────────┤");
    mvwprintw(menu_window, 5, 0, "│                   │");
    mvwprintw(menu_window, 6, 0, "└───────────────────┘");
    if (input_index == 0)
        wattron(menu_window, A_REVERSE);
    mvwprintw(menu_window, 1, 3, " Enter Pokedex ");
    if (input_index == 0)
        wattroff(menu_window, A_REVERSE);

    if (input_index == 1)
        wattron(menu_window, A_REVERSE);
    mvwprintw(menu_window, 3, 2, " Enter Inventory ");
    if (input_index == 1)
        wattroff(menu_window, A_REVERSE);

    if (input_index == 2)
        wattron(menu_window, A_REVERSE);
    mvwprintw(menu_window, 5, 7, " Close ");
    if (input_index == 2)
        wattroff(menu_window, A_REVERSE);
    wrefresh(menu_window);
}
#if 0
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
#endif

void resizeWindowsFix(WINDOW *&main_window, int &input_index)
{
    clear();
    refresh();

    wresize(main_window, 37, 152);
    mvwin(main_window, 0, 0);
    wclear(main_window);
    box(main_window, 0, 0);
    wrefresh(main_window);

    drawPokemonLogo(main_window, 4, 42);
    drawCondensedMoveButtons(main_window, 31, 109);
    drawChooseButton(main_window, 31, 126);
    redrawMenuWindow(main_window, 21, 66, input_index);
}

int main()
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
#define SETUP
#ifdef SETUP
#if 1
    std::vector<PokedexPokemon> pokedex;
    fillPokedex("pokedex.txt", pokedex);
#endif
#define COLOR_SETUP
#ifdef COLOR_SETUP
    init_pair(static_cast<short>(Type::Normal), COLOR_WHITE, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Fire), 196, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Water), 4, COLOR_BLACK);
    init_pair(static_cast<short>(Type::Electric), 11, COLOR_BLACK);
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
    init_pair(static_cast<short>(Type::Electric) + 20, 11, COLOR_WHITE);
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

    WINDOW *main_window = newwin(37, 152, 0, 0);
    box(main_window, 0, 0);
    wrefresh(main_window);
#endif

    [[maybe_unused]] int input_index = 0;
    int ch = 0;
    bool window_too_small = false;

    drawPokemonLogo(main_window, 4, 42);
    drawCondensedMoveButtons(main_window, 31, 109);
    drawChooseButton(main_window, 31, 126);
    redrawMenuWindow(main_window, 21, 66, input_index);
    while ((ch = getch()) != '\n' || input_index != 2)
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
                resizeWindowsFix(main_window, input_index);
            }
            else
            {
                resizeWindowsFix(main_window, input_index);
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
            input_index = (input_index == 0) ? 2 : input_index - 1;
            break;
        case KEY_DOWN:
            input_index = (input_index == 2) ? 0 : input_index + 1;
            break;
        case '\n':
            if (input_index == 0)
            {
                mainPokedex();
                box(main_window, 0, 0);
                drawPokemonLogo(main_window, 4, 42);
                drawCondensedMoveButtons(main_window, 31, 109);
                drawChooseButton(main_window, 31, 126);
            }
            else if (input_index == 1)
            {
                mainInventory();
                box(main_window, 0, 0);
                drawPokemonLogo(main_window, 4, 42);
                drawCondensedMoveButtons(main_window, 31, 109);
                drawChooseButton(main_window, 31, 126);
            }
            break;
        default:
            break;
        }
        // mvwprintw(main_window, 1, 1, "input_index is %d", input_index);
        redrawMenuWindow(main_window, 21, 66, input_index);
        wrefresh(main_window);
    }

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
 │  Evo tree: Dratini->Dragonair->Dragonite   │
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
