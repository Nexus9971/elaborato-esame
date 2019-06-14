//
// Created by Mario De Simone on 2019-06-12.
//
#ifndef PROGETTOPROGRAMMAZIONE_DATE_H
#define PROGETTOPROGRAMMAZIONE_DATE_H

class Date{
public:
    explicit Date(int d = 1, int m = 1, int y = 2019);

    const int getDay() const {
        return day;
    }

    const int getMonth() const {
        return month;
    }

    const int getYear() const {
        return year;
    }

    bool operator==(const Date& d) const;
private:
    int day;
    int month;
    int year;
};

#endif //PROGETTOPROGRAMMAZIONE_DATE_H
