//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Account& p, Account& b, const std::string& i, const Date& d, double a, const Category& c) throw(std::out_of_range) :
                        id(i), type(c), date_transaction(std::unique_ptr<Date>(new Date(d))){
    if(a > 0){
        Transaction::amount = a;
    }else{
        throw std::out_of_range("Error amount negative");
    }
    Transaction::payer = p.getPerson();
    Transaction::beneficiary = b.getPerson();
    p.removeMoney(Transaction::amount);
    b.addMoney(Transaction::amount);
}

bool Transaction::operator==(const Transaction& t) const{
    bool result = false;
    if(*Transaction::date_transaction == t.getDateTransaction() && Transaction::getBeneficiary() == t.getBeneficiary() &&
       Transaction::getPayer() == t.getPayer() && Transaction::amount == t.getAmount() && Transaction::type == t.getType()){
        result = true;
    }
    return result;
}