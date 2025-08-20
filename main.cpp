#include <iostream>
#include <ncurses.h>
#include <unistd.h>

int main() {

    initscr();
    start_color();               // Abilita i colori
    init_pair(2, COLOR_RED, COLOR_BLACK);  // Definisce coppia colori

    attron(COLOR_PAIR(1));       // Usa coppia colori 1
    printw("Testo rosso su nero\n");
    attroff(COLOR_PAIR(1));      // Disattiva

    printw("Testo normale\n");
    refresh();
    getch();
    endwin();
    return 0;

}


