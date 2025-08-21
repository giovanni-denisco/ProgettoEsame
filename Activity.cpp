
#include <iostream>
#include "Activity.h"

void Activity::setTimeStart() {

    bool validHour = false;
    bool validMin = false;
    while (!validHour) {
        std::cout << "Inserisci ora di inizio:" << std::endl;
        std::cin >> hourTimeStart;
        if (hourTimeStart < 0 || hourTimeStart > 23)
            std::cout << "Ora non valida!" << std::endl;
        else
            validHour = true;
    }

    while (!validMin) {
        std::cout << "Inserisci minuti di inizio:" << std::endl;
        std::cin >> minTimeStart;
        if (minTimeStart < 0 || minTimeStart > 59)
            std::cout << "Minuti non validi!" << std::endl;
        else
            validMin = true;
    }
}

void Activity::setTimeEnd() {

    bool validHour = false;
    bool validMin = false;
    while (!validHour || !validMin) {
        std::cout << "Inserisci ora di fine:" << std::endl;
        std::cin >> hourTimeEnd;
        if (hourTimeEnd < 0 || hourTimeEnd > 23)
            std::cout << "Ora non valida!" << std::endl;
        else
            validHour = true;

        std::cout << "Inserisci minuti di fine:" << std::endl;
        std::cin >> minTimeEnd;
        if (minTimeEnd < 0 || minTimeEnd > 59)
            std::cout << "Minuti non validi!" << std::endl;
        else if (hourTimeEnd < hourTimeStart || (hourTimeEnd == hourTimeStart && minTimeEnd <= minTimeStart)) {
            std::cout << "Durata non valida!" << std::endl;
            validHour = false;
            validMin = false;
        }
        else
            validMin = true;
    }
}









