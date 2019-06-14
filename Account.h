//
// Created by Mario De Simone on 2019-06-12.
//

#ifndef PROGETTOPROGRAMMAZIONE_ACCOUNT_H
#define PROGETTOPROGRAMMAZIONE_ACCOUNT_H

#include "Date.h"
#include "Transaction.h"
#include <string>
#include <list>
#include <utility>
#include <fstream>
#include <sstream>

class Transaction;//Forward Declaration to avoid inclusion problem

class Account {
public:
    Account(const std::string& n, const std::string& s, const Date& c = Date(), int m = 0);
    const std::pair<std::string, std::string>& getPerson() const{
        return person;
    }
    const int getMoney() const {
        return money;
    }

    void addMoney(int money);
    void removeMoney(int money);
    void insertTransaction(Transaction& t);
private:
    std::pair<std::string, std::string> person;
    Date creation;
    int money;
    std::list<unique_ptr<Transaction>> transactions;
};


#endif //PROGETTOPROGRAMMAZIONE_ACCOUNT_H
