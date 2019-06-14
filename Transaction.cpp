//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Account& p, Account& b, const Date& d, int a, const Category& c): date_transaction(d), amount(a), type(c){
    payer = p.getPerson();
    beneficiary = b.getPerson();
    p.removeMoney(a);
    b.addMoney(a);
};