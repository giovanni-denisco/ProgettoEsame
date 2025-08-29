
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class Activity {
public:

    //Metodi getter
    int getHourTimeStart() const;
    int getMinTimeStart() const;
    int getHourTimeEnd() const;
    int getMinTimeEnd() const;
    std::string getDescription() const;
    std::string getTitle() const;


    //Metodi setter
    void setHourTimeStart(int h);
    void setMinTimeStart(int m);
    void setHourTimeEnd(int h);
    void setMinTimeEnd(int m);
    void setDescription(const std::string& desc);
    void setTitle(const std::string& t);

private:

    //Attributi
    int hourTimeStart, minTimeStart;
    int hourTimeEnd, minTimeEnd;
    std::string description;
    std::string title;
};



#endif //FUNCTIONS_H
