//
// Created by Mario De Simone on 2019-06-14.
//

#include "../Transaction.h"
#include "../Account.h"
#include <utility>
#include <string>

#include "gtest/gtest.h"

TEST(Account, ConstructorDefaultParameters){
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Account a("Mario", "De Simone");
    ASSERT_EQ(a.getMoney(), 0);
    ASSERT_EQ(a.getCreation(), Date());
    ASSERT_EQ(a.getPerson(), p);
}

TEST(Account, ConstructorWrongParameters){
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Account a("Mario", "De Simone", Date(), -1);
    ASSERT_EQ(a.getMoney(), 0);
    ASSERT_EQ(a.getCreation(), Date());
    ASSERT_EQ(a.getPerson(), p);
}

TEST(Account, TestaddMoney){
    Account a("Mario", "De Simone");
    a.addMoney(10);
    ASSERT_EQ(a.getMoney(), 10);
}

TEST(Account, TestremoveMoney){
    Account a("Mario", "De Simone");
    a.removeMoney(10);
    ASSERT_EQ(a.getMoney(), -10);
}

TEST(Account, TestinsertTransaction){
    Date d(2, 2, 2020);
    Account first("Mario", "De Simone", d, 10);
    Account second("Napoleone", "Bonaparte", d, 5);
    Transaction t(first, second, d, 4);
    first.insertTransaction(t);
    second.insertTransaction(t);
    ASSERT_EQ(*first.getTransactions().back(), t);
    ASSERT_EQ(*second.getTransactions().back(), t);
}