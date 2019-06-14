//
// Created by Mario De Simone on 2019-06-12.
//

#include "Date.h"

Date::Date(int d, int m, int y){
    if(y >= 2000){
        Date::year = y;
    }else{
        Date::year = 2019;
    }
    if(m >= 1 && m <=12){
        Date::month = month;
    }else{
        Date::month = 1;
    }
    if(d <= 0 || d >= 32){
        Date::day = 1;
    }else if((Date::month == 4 || Date::month == 6 || Date::month == 9 || Date::month == 11) && d >= 31){
        Date::day = 1;
    }else if((Date::month == 1 || Date::month == 3 || Date::month == 5 || Date::month == 7 || Date::month == 8
              || Date::month == 10 || Date::month == 12) && d >= 32){
        Date::day = 1;
    }else if((Date::month == 2 && (Date::year%4) == 0) && d >= 30){
        Date::day = 1;
    }else if(Date::month == 2 && d >= 29){
        Date::day = 1;
    }else{
        Date::day = day;
    }

}