#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();

    // Check if the terminal supports colors
    if (!has_colors()) {
        endwin();
        printf("Your terminal does not support color.\n");
        return 1;
    }

    // Start color functionality
    start_color();

    // Initialize color pairs
    for (short i = 0; i < COLORS && i < 256; i++) {
        init_pair(i, i, COLOR_BLACK);
    }

    // Display the colors
    for (int i = 0; i < COLORS && i < 256; i++) {
        attron(COLOR_PAIR(i));
        printw("%4d", i);
        attroff(COLOR_PAIR(i));
    }

    // Refresh the screen to show changes
    refresh();

    // Wait for user input
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
