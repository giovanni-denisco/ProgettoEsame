
#include <iostream>
#include <vector>
#include <ncurses.h>
#include "Register.h"


void Register::addActivity(const Activity& a) {
    activities.push_back(a);
}

void Register::removeActivity(int index) {
    if (index >= 0 && index < activities.size()) {
        activities.erase(activities.begin() + index);
    } else {
        std::cout << "Indice non valido!" << std::endl;
    }
}

//Funzione per visualizzare eventuali attività
void Register::showActivities() const {
    if (activities.empty()) {
        printw("Nessuna attività presente\n");
        return;
    }

    for (size_t i = 0; i < activities.size(); ++i) {
        printw("Attività %zu: %s: %s (%02d:%02d - %02d:%02d)\n",
               i + 1,
               activities[i].getTitle().c_str(),
               activities[i].getDescription().c_str(),
               activities[i].getHourTimeStart(),
               activities[i].getMinTimeStart(),
               activities[i].getHourTimeEnd(),
               activities[i].getMinTimeEnd());
    }
}
