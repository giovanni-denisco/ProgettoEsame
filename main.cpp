#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Activity.h"
#include "Register.h"
#include "Menu.h"

//Lancio Programma

int main() {
    Register registro;
    showMenu(registro);
    return 0;
}


