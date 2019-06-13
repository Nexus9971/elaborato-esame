//
// Created by Mario De Simone on 2019-06-12.
//

#include "Account.h"

Account::Account(std::string n, std::string s, Date c, int m) : creation(c){
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
    Account::transactions.push_back(std::unique_ptr<Transaction>(&t));
}