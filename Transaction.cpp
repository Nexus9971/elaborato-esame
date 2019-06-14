//
// Created by Mario De Simone on 2019-06-13.
//

#include "Transaction.h"

Transaction::Transaction(Account& p, Account& b, const Date& d, int a, const Category& c): date_transaction(d), amount(a), type(c){
    Transaction::payer = p.getPerson();
    Transaction::beneficiary = b.getPerson();
    p.removeMoney(a);
    b.addMoney(a);
};

bool Transaction::operator==(const Transaction &t) const{
    bool result = false;
    if(Transaction::date_transaction == t.date_transaction && Transaction::beneficiary == t.beneficiary &&
       Transaction::payer == t.payer && Transaction::amount == t.amount && Transaction::type == t.type){
        result = true;
    }
    return result;
}