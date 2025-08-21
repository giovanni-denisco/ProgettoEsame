
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Activity {
public:
    void setTimeStart();
    void setTimeEnd();
    void setDescription(std::string desc);

private:
    int hourTimeStart, minTimeStart;
    int hourTimeEnd, minTimeEnd;
    std::string description;
};



#endif //FUNCTIONS_H
