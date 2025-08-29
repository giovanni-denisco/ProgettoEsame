
#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>
#include "Activity.h"

class Register {
public:
    //Metodi
    void addActivity(const Activity& a);
    void removeActivity(int index);
    void showActivities() const;
    bool isEmpty() const;
    int numberActivities() const;
private:
    //Creazione Vettore per gestire Inserimento e Rimozione Attività
    std::vector<Activity> activities;
};




#endif //REGISTER_H
