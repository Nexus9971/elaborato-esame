//
// Created by Mario De Simone on 2019-06-12.
//
#ifndef PROGETTOPROGRAMMAZIONE_DATE_H
#define PROGETTOPROGRAMMAZIONE_DATE_H

#include "stdexcept"
#include <string>
#include <sstream>

enum class Months{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

class Date{
public:
    Date(int d, Months m, int y) throw(std::out_of_range);

    const int getDay() const {
        return day;
    }

    const Months getMonth() const {
        return month;
    }

    const int getYear() const {
        return year;
    }

    const std::string dateToString() const;

    bool operator==(const Date& d) const;
private:
    int day;
    Months month;
    int year;

    const int getMaxDay() const;
};

#endif //PROGETTOPROGRAMMAZIONE_DATE_H
