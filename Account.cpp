//
// Created by Mario De Simone on 2019-06-12.
//

#include "Account.h"

Account::Account(const std::string& n, const std::string& s, const std::string& i, const Date& c, double m) throw(std::out_of_range) :
                id(i), creation(std::unique_ptr<Date>(new Date(c))){
    person.first = s;
    person.second = n;
    if(m >= 0){
        money = m;
    }else{
        throw std::out_of_range("Error negative starting credit");
    }
}

void Account::addMoney(double m) {
    money += m;
}

void Account::removeMoney(double m) {
    money -= m;
}

void Account::insertTransaction(Transaction& t) {
    if(id == t.getId().first || id == t.getId().second){
        transactions.push_back(std::unique_ptr<Transaction>(new Transaction(std::move(t))));
        std::ofstream fileTransaction;
        std::string path = "../ListTransactions/" + person.first +  person.second + ".txt";
        fileTransaction.open(path, std::ofstream::app);
        std::stringstream stream;
        stream << "Transaction from "  << t.getPayer() << " (" << t.getId().first << ")" << " to " << t.getBeneficiary() << " ("
                << t.getId().second << ")" << " of " << t.getAmount() << "€ " << "in " << t.getDateTransaction().dateToString() << "\n";
        fileTransaction << stream.str();
        fileTransaction.close();
    }
}