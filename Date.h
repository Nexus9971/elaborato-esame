//
// Created by Mario De Simone on 2019-06-12.
//
#include <string>
#include <utility>
#include <map>

#ifndef PROGETTOPROGRAMMAZIONE_DATE_H
#define PROGETTOPROGRAMMAZIONE_DATE_H


class Date{

private:
    int day;
    std::pair<int, std::string> month;
    int year;

public:
    Date(int d = 1, std::pair<int, std::string> m = std::make_pair(1, "January"), int y = 2019) : day(d), year(y), month(m){};
    int getDay() const {
        return day;
    }

    bool setDay(int day) {
        bool result = true;
        if(day <= 0 || day >= 32){
            result = false;
        }else if((month.second == "April" || month.second == "June" || month.second == "September" || month.second == "November") && day >= 31){
            result = false;
        }else if((month.second == "January" || month.second == "March" || month.second == "May" || month.second == "July" || month.second == "August"
                || month.second == "October" || month.second == "December") && day >= 32){
            result = false;
        }else if((month.second == "February" && (year%4) == 0) && day >= 30){
            result = false;
        }else if(month.second == "February" && day >= 29){
            result = false;
        }
        if(result){
            Date::day = day;
        }else{
            Date::day = day;
        }
        return result;
    }

    std::pair<int, std::string> getMonth() const {
        return month;
    }

    void setMonth(std::pair<int, std::string> month) {
        Date::month = month;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }
};

#endif //PROGETTOPROGRAMMAZIONE_DATE_H
