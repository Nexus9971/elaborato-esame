//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Account& p, Account& b, const Date& d, int a, const Category& c): date_transaction(d), type(c){
    if(a >= 0){
        Transaction::amount = a;
    }else{
        Transaction::amount = 0;
    }
    Transaction::payer = p.getPerson();
    Transaction::beneficiary = b.getPerson();
    p.removeMoney(Transaction::amount);
    b.addMoney(Transaction::amount);
}

bool Transaction::operator==(const Transaction& t) const{
    bool result = false;
    if(Transaction::date_transaction == t.getDateTransaction() && Transaction::getBeneficiary() == t.getBeneficiary() &&
       Transaction::getPayer() == t.getPayer() && Transaction::amount == t.getAmount() && Transaction::type == t.getType()){
        result = true;
    }
    return result;
}