
#include <iostream>
#include <vector>
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

void Register::showActivities() const {
    if (activities.empty()) {
        std::cout << "Nessuna attività presente" << std::endl;
        return;
    }

    for (size_t i = 0; i < activities.size(); ++i) {
        std::cout << "Attività " << i << ": "
                  << activities[i].getDescription()
                  << " (" << activities[i].getHourTimeStart() << ":"
                  << activities[i].getMinTimeStart() << " - "
                  << activities[i].getHourTimeEnd() << ":"
                  << activities[i].getMinTimeEnd() << ")"
                  << std::endl;
    }
}
