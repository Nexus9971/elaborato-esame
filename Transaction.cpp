//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Account& p, Account& b, const Date& d, double a, const Category& c) throw(std::out_of_range) :
                        type(c), date_transaction(std::unique_ptr<Date>(new Date(d))){
    id.first = p.getId();
    id.second = b.getId();
    if(a > 0){
        amount = a;
    }else{
        throw std::out_of_range("Error amount negative");
    }
    payer = p.getPerson();
    beneficiary = b.getPerson();
    p.removeMoney(amount);
    b.addMoney(amount);
}

bool Transaction::operator==(const Transaction& t) const{
    bool result = false;
    if(*date_transaction == *t.date_transaction && beneficiary == t.beneficiary &&
       payer == t.payer && amount == t.amount && type == t.type){
        result = true;
    }
    return result;
}