//
// Created by Mario De Simone on 2019-06-12.
//

#include "Date.h"

Date::Date(int d, Months m, int y) throw(std::out_of_range){
    month = m;
    if (y <= 0){
        throw std::out_of_range("Date Error");
    }else{
        year = y;
    }
    int max = getMaxDay();
    if(d <= 0 || d > max){
        throw std::out_of_range("Date Error");
    }else{
        day = d;
    }
}

const int Date::getMaxDay() const{
    int max;
    switch(month){
        case Months::April:
        case Months::June:
        case Months::September:
        case Months::November:
            max = 30;
            break;
        case Months::February: {
            if ((year % 4) == 0) {
                if ((year % 100) == 0){
                    if ((year % 400) == 0){
                        max = 29;
                    }else{
                        max = 28;
                    }
                }else{
                    max = 29;
                }
            }else{
                max = 28;
            }
            break;
        }
        default: {
            max = 31;
            break;
        }
    }
    return max;
}

bool Date::operator==(const Date &d) const{
    bool result = false;
    if(Date::day == d.getDay() && Date::month == d.getMonth() && Date::year == d.getYear()){
        result = true;
    }
    return result;
}

const std::string Date::dateToString() const{
    std::string m;
    switch(month){
        case Months::January:{m = "January"; break;}
        case Months::February:{m = "February"; break;}
        case Months::March:{m = "March"; break;}
        case Months::April:{m = "April"; break;}
        case Months::May:{m = "May"; break;}
        case Months::June:{m = "June"; break;}
        case Months::July:{m = "July"; break;}
        case Months::August:{m = "August"; break;}
        case Months::September:{m = "September"; break;}
        case Months::October:{m = "October"; break;}
        case Months::November:{m = "November"; break;}
        case Months::December:{m = "December"; break;}
    }
    std::stringstream stream;
    stream << day << " " << m << " " << year;
    return stream.str();
}