#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Activity.h"
#include "Register.h"

int main() {

    //Inizializzazione NCurses
    initscr();
    noecho();
    cbreak();

    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    //Creazione finestra menù
    WINDOW * menuWindow = newwin(0, 0, 0, 0);
    box(menuWindow, 0, 0);
    refresh();
    wrefresh(menuWindow);

    keypad(menuWindow, true);

    getch();
    endwin();

    return 0;


}


