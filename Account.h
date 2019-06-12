//
// Created by Mario De Simone on 2019-06-12.
//

#ifndef PROGETTOPROGRAMMAZIONE_ACCOUNT_H
#define PROGETTOPROGRAMMAZIONE_ACCOUNT_H

#include "string"
#include "Date.h"

class Account {
private:
    std::string name;
    std::string surname;
    Date creation;
    int money;


public:
    Account(std::string n = "", std::string s = "", Date c = Date(), int m = 0);
    const std::string& getName() const {
        return name;
    }

    const std::string& getSurname() const {
        return surname;
    }
    int getMoney() const {
        return money;
    }

    void addMoney(int money);
    void removeMoney(int money);
};


#endif //PROGETTOPROGRAMMAZIONE_ACCOUNT_H
