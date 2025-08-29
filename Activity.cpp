
#include <stdexcept>
#include "Activity.h"

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








