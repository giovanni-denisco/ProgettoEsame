
#include "Menu.h"
#include <ncurses.h>

void showMenu(Register& registro) {

    //Inizializzazione NCurses
    initscr();      //Inizializzione
    noecho();       //Nasconde Tasti Premuti
    cbreak();       //Preparazione Tasti Inseriti

    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    //Creazione finestra menù
    WINDOW * menuWindow = newwin(0, 0, 0, 0);
    box(menuWindow, 0, 0);
    refresh();
    wrefresh(menuWindow);

    keypad(menuWindow, true);

    std::string choices[4] = {"Mostra Attività", "Aggiungi Attività", "Rimuovi Attività", "Esci"};
    int choice;
    int highlight = 0;

    //Ciclo per Scelta nel Menù
    while (1) {
        werase(menuWindow);
        box(menuWindow, 0, 0);
        for (int i = 0; i < 4; i++) {
            if (i == highlight)
                wattron(menuWindow, A_REVERSE);
            mvwprintw(menuWindow, i+1, 1, choices[i].c_str());
            wattroff(menuWindow, A_REVERSE);
        }

        choice = wgetch(menuWindow);

        //Selezione Voci in modo Circolare
        switch (choice) {
            case KEY_UP:
                highlight--;
            if (highlight == -1)
                highlight = 3;
            break;
            case KEY_DOWN:
                highlight++;
            if (highlight == 4)
                highlight = 0;
            break;

            //Scelta Opzione
            case 10:
                //Mostra Attività
                if (highlight == 0) {
                    clear();
                    registro.showActivities();
                    printw("\nPremi un tasto per tornare al menù...");
                    getch();
                }
                // Aggiungi attività
                else if (highlight == 1) {
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
                //Rimuovi Attività
                else if (highlight == 2) {
                    clear();
                    registro.showActivities();

                    if (registro.isEmpty()) {
                        printw("\nNessuna attività da eliminare.");
                        getch();
                    }
                    else {
                        bool valid = false;

                        while (!valid) {
                            printw("\nInserisci l'indice dell'attività da eliminare: ");
                            refresh();
                            echo();
                            int index;
                            scanw("%d", &index);
                            noecho();
                            //Controlli indice inserito
                            if (index < 1 || index > registro.numberActivities()) {
                                printw("Indice non valido!");
                            }
                            else {
                                registro.removeActivity(index-1);
                                valid = true;
                            }
                        }
                    }
                }
            //Uscita dal Menù
                else if (highlight == 3) {
                    endwin();
                    return;
                }
            default:
                break;
        }
    }

    getch();
}