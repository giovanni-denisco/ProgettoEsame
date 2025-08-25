
#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <vector>
#include "Activity.h"

class Register {
public:
    void addActivity(const Activity& a);
    void removeActivity(int index);
    void showActivities() const;
private:
    std::vector<Activity> activities;
};




#endif //REGISTER_H
