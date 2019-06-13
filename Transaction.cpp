//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Date d, int a, Account& p, Account& b): date_transaction(d), amount(a){
    payer.first = p.getSurname();
    payer.second = p.getName();
    beneficiary.first = b.getSurname();
    beneficiary.second = b.getName();
    p.removeMoney(a);
    b.addMoney(a);
};