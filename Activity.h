
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Activity {
public:
    //Metodi
    void userTimeStart();
    void userTimeEnd();
    void userDescription();

    //Metodi getter
    int getHourTimeStart() const;
    int getMinTimeStart() const;
    int getHourTimeEnd() const;
    int getMinTimeEnd() const;
    std::string getDescription() const;

    //Metodi setter
    void setHourTimeStart(int h);
    void setMinTimeStart(int m);
    void setHourTimeEnd(int h);
    void setMinTimeEnd(int m);
    void setDescription(const std::string& desc);

private:
    int hourTimeStart, minTimeStart;
    int hourTimeEnd, minTimeEnd;
    std::string description;
};



#endif //FUNCTIONS_H
