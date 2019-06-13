//
// Created by Mario De Simone on 2019-06-12.
//
#ifndef PROGETTOPROGRAMMAZIONE_DATE_H
#define PROGETTOPROGRAMMAZIONE_DATE_H

class Date{

private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 2019);

    const int getDay() const {
        return day;
    }

    bool setDay(int day);

    const int getMonth() const {
        return month;
    }

    bool setMonth(int month);

    const int getYear() const {
        return year;
    }

    bool setYear(int year);
};

#endif //PROGETTOPROGRAMMAZIONE_DATE_H
