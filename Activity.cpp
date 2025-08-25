
#include <iostream>
#include <stdexcept>
#include "Activity.h"

void Activity::userTimeStart() {

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

void Activity::userTimeEnd() {

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

void Activity::userDescription() {
    std::cout << "Inserisci descrizione dell'attività:" << std::endl;
    std::getline(std::cin, description);
}

void Activity::userTitle() {
    std::cout << "Inserisci titolo attività" << std::endl;
    std::getline(std::cin, title);
}

//Metodi getter

int Activity::getHourTimeStart() const {
    return hourTimeStart;
}

int Activity::getMinTimeStart() const {
    return minTimeStart;
}

int Activity::getHourTimeEnd() const {
    return hourTimeEnd;
}

int Activity::getMinTimeEnd() const {
    return minTimeEnd;
}

std::string Activity::getDescription() const {
    return description;
}

std::string Activity::getTitle() const {
    return title;
}


//Metodi setter

void Activity::setHourTimeStart(int h) {
    if (h < 0 || h > 23)
        throw std::invalid_argument("Ora di inizio non valida (0-23)");
    hourTimeStart = h;
}

void Activity::setMinTimeStart(int m) {
    if (m < 0 || m > 59)
        throw std::invalid_argument("Minuti di inizio non validi (0-59)");
    minTimeStart = m;
}

void Activity::setHourTimeEnd(int h) {
    if (h < 0 || h > 23)
        throw std::invalid_argument("Ora di fine non valida (0-23)");
    hourTimeEnd = h;
}

void Activity::setMinTimeEnd(int m) {
    if (m < 0 || m > 59)
        throw std::invalid_argument("Minuti di fine non validi (0-59)");
    minTimeEnd = m;
}

void Activity::setDescription(const std::string& desc) {
    description = desc;
}

void Activity::setTitle(const std::string& t) {
    title = t;
}








