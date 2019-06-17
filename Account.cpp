//
// Created by Mario De Simone on 2019-06-12.
//

#include "Account.h"

Account::Account(const std::string& n, const std::string& s, const std::string& i, const Date& c, double m) throw(std::out_of_range) :
                id(i), creation(std::unique_ptr<Date>(new Date(c))){
    person.first = s;
    person.second = n;
    if(m >= 0){
        Account::money = m;
    }else{
        throw std::out_of_range("Error negative starting credit");
    }
}

void Account::addMoney(double money) {
    Account::money += money;
}

void Account::removeMoney(double money) {
    Account::money -= money;
}

void Account::insertTransaction(Transaction& t) {
    Account::transactions.push_back(std::unique_ptr<Transaction>(std::move(new Transaction(std::move(t)))));
    std::ofstream fileTransaction;
    std::string path = "../ListTransactions/" + Account::person.first +  Account::person.second + ".txt";
    fileTransaction.open(path, std::ofstream::app);
    std::stringstream stream;
    stream << "Transaction with ID" << t.getId() << " from " << t.getPayer() << " to " << t.getBeneficiary() << " of " << t.getAmount()
                                << "€ " << "in " << t.getDateTransaction().getDay() << "/" << t.getDateTransaction().dateToString() << "\n";
    fileTransaction << stream.str();
    fileTransaction.close();
}