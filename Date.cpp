//
// Created by Mario De Simone on 2019-06-12.
//

#include "Date.h"

Date::Date(int d, int m, int y): day(d), year(y), month(m){

}

bool Date::setDay(int day){
    bool result = true;
    if(day <= 0 || day >= 32){
        result = false;
    }else if((month == 4 || month == 6 || month == 9 || month == 11) && day >= 31){
        result = false;
    }else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8
              || month == 10 || month == 12) && day >= 32){
        result = false;
    }else if((month == 2 && (year%4) == 0) && day >= 30){
        result = false;
    }else if(month == 2 && day >= 29){
        result = false;
    }
    if(result){
        Date::day = day;
    }
    return result;
}

bool Date::setMonth(int month) {
    bool result = true;
    if(month >= 1 && month <=12){
        Date::month = month;
    }else{
        result = false;
    }
    return result;
}

bool Date::setYear(int year) {
    bool result = true;
    if(year >= 2000){
        Date::year = year;
    }else{
        result = false;
    }
    return result;
}