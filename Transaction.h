//
// Created by Mario De Simone on 2019-06-13.
//

#ifndef PROGETTOPROGRAMMAZIONE_TRANSACTION_H
#define PROGETTOPROGRAMMAZIONE_TRANSACTION_H

#include "Date.h"
#include "Account.h"
#include <stdexcept>
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
    Transaction(Account& p, Account& b, const std::string& i, const Date& d, double a, const Category& c = Category::other) throw(std::out_of_range);
    const Date& getDateTransaction() const {
        return *date_transaction;
    }

    const double getAmount() const {
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

    const std::string& getId() const {
        return id;
    }

    bool operator==(const Transaction& t) const;
private:
    std::unique_ptr<Date> date_transaction;
    std::string id;
    double amount;
    std::pair<std::string, std::string> payer;
    std::pair<std::string, std::string> beneficiary;
    Category type;
};

#endif //PROGETTOPROGRAMMAZIONE_TRANSACTION_H
