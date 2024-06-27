#include <ncurses.h>
#include <locale.h>
#include <unistd.h> // For usleep

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    noecho();
    curs_set(FALSE);

    // Create main window
    WINDOW *main_win = newwin(13, 46, 1, 1);
    // box(main_win, 0, 0);
    mvwprintw(main_win, 0, 0, "┌─────┬────────────┬─────────────────────────┐");
    mvwprintw(main_win, 1, 0, "│     │            │                         │");
    mvwprintw(main_win, 2, 0, "├─────┴────────────┴──┬──────────────────────┤");
    mvwprintw(main_win, 3, 0, "│                     │                      │");
    mvwprintw(main_win, 4, 0, "├─────────────────────┴──────────────────────┤");
    mvwprintw(main_win, 5, 0, "│                                            │");
    mvwprintw(main_win, 6, 0, "├────────────────────────────────────────────┤");
    mvwprintw(main_win, 7, 0, "│                                            │");
    mvwprintw(main_win, 8, 0, "│                                            │");
    mvwprintw(main_win, 9, 0, "│                                            │");
    mvwprintw(main_win, 10, 0, "│                                            │");
    mvwprintw(main_win, 11, 0, "│                                            │");
    mvwprintw(main_win, 12, 0, "└────────────────────────────────────────────┘");
    refresh();
    wrefresh(main_win);
    const char * text = "003\0";
    int x=2;
    // Create subwindow
    WINDOW *sub_win = subwin(main_win, 3, 7, 1, 1);
    // box(sub_win, 0, 0);
    // mvwprintw(sub_win, 1, 1, " 003 ");
    while(*text){
        mvwaddch(sub_win,1,x,*text);
        wrefresh(sub_win);
        usleep(100000);
        text++;
        x++;
    }
    refresh();
    wrefresh(sub_win);

    // Create subwindow
    WINDOW *sub_win2 = subwin(main_win, 3, 14, 1, 7);
    // box(sub_win2, 0, 0);
    mvwprintw(sub_win2, 1, 1, " 1234567891");
    refresh();
    wrefresh(sub_win2);

    // Create subwindow
    WINDOW *sub_win3 = subwin(main_win, 3, 27, 1, 20);
    // box(sub_win3, 0, 0);
    mvwprintw(sub_win3, 1, 1, " Type: 12345678/12345678");
    refresh();
    wrefresh(sub_win3);

    // Create subwindow
    WINDOW *sub_win4 = subwin(main_win, 3, 24, 3, 1);
    // box(sub_win4, 0, 0);
    mvwprintw(sub_win4, 1, 1, " 1234567891");
    refresh();
    wrefresh(sub_win4);

    // Create subwindow
    WINDOW *sub_win5 = subwin(main_win, 3, 24, 3, 23);
    // box(sub_win5, 0, 0);
    mvwprintw(sub_win5, 1, 1, " henlo");
    refresh();
    wrefresh(sub_win5);

    // Create subwindow
    WINDOW *sub_win6 = subwin(main_win, 3, 42, 5, 3);
    // box(sub_win6, 0, 0);
    mvwprintw(sub_win6, 1, 1, "Evo tree:Hello");
    refresh();
    wrefresh(sub_win6);

    // Create subwindow
    WINDOW *sub_win7 = subwin(main_win, 7, 42, 7, 3);
    // box(sub_win7, 0, 0);
    mvwprintw(sub_win7, 1, 1, "The plant blooms when it is absorbing solar energy. It stays on the move to seek sunlight.");
    refresh();
    wrefresh(sub_win7);

    // mvwprintw(main_win, 0, 0, "Input Window");
    refresh();
    
    wrefresh(main_win);

    getch();

    // delwin(sub_win7);
    // delwin(sub_win6);
    // delwin(sub_win5);
    // delwin(sub_win4);
    // delwin(sub_win3);
    // delwin(sub_win2);
    // delwin(sub_win);
    delwin(main_win);
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
