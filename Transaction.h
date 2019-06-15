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

enum class Category{
    car,
    food,
    home,
    entertainment,
    school,
    tax,
    other
};

class Transaction{
public:
    Transaction(Account& p, Account& b, const Date& d = Date(), int a = 0, const Category& c = Category::other);
    const Date& getDateTransaction() const {
        return date_transaction;
    }

    const int getAmount() const {
        return amount;
    }

    const std::string getPayer() const {
        std::string result = payer.first + " " + payer.second;
        return result;
    }

    const std::string getBeneficiary() const {
        std::string result = beneficiary.first + " " + beneficiary.second;
        return result;
    }

    const Category& getType() const {
        return type;
    }

    bool operator==(const Transaction& t) const;
private:
    Date date_transaction;
    int amount;
    std::pair<std::string, std::string> payer;
    std::pair<std::string, std::string> beneficiary;
    Category type;
};

#endif //PROGETTOPROGRAMMAZIONE_TRANSACTION_H
