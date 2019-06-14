//
// Created by Mario De Simone on 2019-06-12.
//

#include "Account.h"

Account::Account(const std::string& n, const std::string& s, const Date& c, int m) : creation(c){
    person.second = n;
    person.first = s;
    if(m >= 0){
        Account::money = m;
    }else{
        Account::money = 0;
    }
}

void Account::addMoney(int money) {
    Account::money += money;
}

void Account::removeMoney(int money) {
    Account::money -= money;
}

void Account::insertTransaction(Transaction& t) {
    Account::transactions.push_back(std::unique_ptr<Transaction>(new Transaction(t)));
    std::ofstream fileTransaction;
    std::string path = "../ListTransactions/" + Account::person.first +  Account::person.second + ".txt";
    fileTransaction.open(path, std::ofstream::app);
    std::stringstream stream;
    stream << "Transaction from " << t.getPayer() << " to " << t.getBeneficiary() << " of " << t.getAmount()
                                << "€ " << "in " << t.getDateTransaction().getDay() << "/" << t.getDateTransaction().getMonth() << "/"
                                << t.getDateTransaction().getYear() << "\n";
    fileTransaction << stream.str();
    fileTransaction.close();
}