#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Activity.h"
#include "Register.h"

int main() {

    Register registro;

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

    std::string choices[3] = {"Mostra Attività", "Aggiungi Attività", "Esci"};
    int choice;
    int highlight = 0;

    while (1) {
        werase(menuWindow);
        box(menuWindow, 0, 0);
        for (int i = 0; i < 3; i++) {
            if (i == highlight)
                wattron(menuWindow, A_REVERSE);
            mvwprintw(menuWindow, i+1, 1, choices[i].c_str());
            wattroff(menuWindow, A_REVERSE);
        }

        choice = wgetch(menuWindow);

        switch (choice) {
            case KEY_UP:
                highlight--;
            if (highlight == -1)
                highlight = 2;
            break;
            case KEY_DOWN:
                highlight++;
            if (highlight == 3)
                highlight = 0;
            break;

            case 10:
                if (highlight == 0) {
                    clear();
                    registro.showActivities();
                    printw("\nPremi un tasto per tornare al menù...");
                    getch();
                }
                else if (highlight == 1) {
                    // Aggiungi attività
                    clear();
                    Activity a;
                    std::string desc;
                    std::string title;
                    int hStart, mStart, hEnd, mEnd;

                    printw("Inserisci titolo: ");
                    echo();
                    char bufferTitle[100];
                    getnstr(bufferTitle, 100);
                    title = bufferTitle;

                    printw("Inserisci descrizione: ");
                    echo();
                    char bufferDesc[100];
                    getnstr(bufferDesc, 100);
                    desc = bufferDesc;

                    //Gestione eccezioni e controllo validità orario
                    bool valid = false;
                    while (!valid) {
                        printw("\nOra inizio: ");
                        scanw("%d", &hStart);
                        printw("Minuti inizio: ");
                        scanw("%d", &mStart);
                        printw("Ora fine: ");
                        scanw("%d", &hEnd);
                        printw("Minuti fine: ");
                        scanw("%d", &mEnd);

                        try {
                            a.setTitle(title);
                            a.setDescription(desc);
                            a.setHourTimeStart(hStart);
                            a.setMinTimeStart(mStart);
                            a.setHourTimeEnd(hEnd);
                            a.setMinTimeEnd(mEnd);

                            if (hEnd < hStart || (hEnd == hStart && mEnd <= mStart)) {
                                throw std::invalid_argument("L'orario di fine deve essere dopo l'inizio");
                            }

                            valid = true;

                        } catch (const std::exception& e) {
                            printw("\nErrore: %s", e.what());
                            printw("\nRiprova a inserire gli orari...\n");
                        }
                    }
                    registro.addActivity(a);
                    printw("\nAttività aggiunta con successo! Premi un tasto...");
                    getch();
                }
                else if (highlight == 2) {
                    endwin();
                    return 0;
                }
            default:
                break;
        }
    }

    getch();
    endwin();

    return 0;


}


