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

class Transaction{
private:
    Date date_transaction;
    int amount;
    std::pair<std::string, std::string> payer;
    std::pair<std::string, std::string> beneficiary;
public:
    Transaction(Date d, int a, Account& p, Account& b);
    const Date& getDateTransaction() const {
        return date_transaction;
    }

    int getAmount() const {
        return amount;
    }
};

#endif //PROGETTOPROGRAMMAZIONE_TRANSACTION_H
