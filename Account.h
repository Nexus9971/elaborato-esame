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
#include <stdexcept>

class Transaction;//Forward Declaration to avoid inclusion problem

class Account {
public:
    Account(const std::string& n, const std::string& s, const std::string& i, const Date& c, double m) throw(std::out_of_range);
   const std::pair<std::string, std::string>& getPerson(){
       return person;
   }

    const std::string& getId() const {
        return id;
    }

    const double getMoney() const {
        return money;
    }

    const Date& getCreation() const {
        return *creation;
    }

    const std::list<std::unique_ptr<Transaction> >& getTransactions() const {
        return transactions;
    }

    void addMoney(double money);
    void removeMoney(double money);
    void insertTransaction(Transaction& t);
private:
    std::pair<std::string, std::string> person;
    std::string id;
    std::unique_ptr<Date> creation;
    double money;
    std::list<std::unique_ptr<Transaction> > transactions;
};


#endif //PROGETTOPROGRAMMAZIONE_ACCOUNT_H
