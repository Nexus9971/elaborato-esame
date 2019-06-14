//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(const Date& d, int a, const Category& c, Account& p, Account& b): date_transaction(d), amount(a), type(c){
    payer = p.getPerson();
    beneficiary = b.getPerson();
    p.removeMoney(a);
    b.addMoney(a);
};