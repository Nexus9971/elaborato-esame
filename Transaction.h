//
// Created by Mario De Simone on 2019-06-13.
//

#ifndef PROGETTOPROGRAMMAZIONE_TRANSACTION_H
#define PROGETTOPROGRAMMAZIONE_TRANSACTION_H

#include "Date.h"
#include "Account.h"
#include <string>
#include <utility>

class Account;

enum Category : char{
    car = 'C';
    food = 'F';
    home = 'H';
    entertainment = 'E';
    school = 'S';
    tax = 'T';
    other = 'O';
};

class Transaction{
private:
    Date date_transaction;
    int amount;
    std::pair<std::string, std::string> payer;
    std::pair<std::string, std::string> beneficiary;
    Category type;
public:
    Transaction(Date d, int a, Category& c, Account& p, Account& b);
    const Date& getDateTransaction() const {
        return date_transaction;
    }

    const int getAmount() const {
        return amount;
    }
    const std::pair<std::string, std::string>& getPayer() const {
        return payer;
    }

    const std::pair<std::string, std::string>& getBeneficiary() const {
        return beneficiary;
    }

    Category getType() const {
        return type;
    }
};

#endif //PROGETTOPROGRAMMAZIONE_TRANSACTION_H
