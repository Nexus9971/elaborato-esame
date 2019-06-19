//
// Created by Mario De Simone on 2019-06-14.
//

#include "../Transaction.h"
#include "../Account.h"
#include <stdexcept>
#include <utility>
#include <string>

#include "gtest/gtest.h"

TEST(Account, ConstructorRightParameters){
    bool result = true;
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Date d(2, Months::February, 2020);
    try {
        Account a("Mario", "De Simone", "IT3548D", d, 1000);
        ASSERT_EQ(a.getMoney(), 1000);
        ASSERT_EQ(a.getCreation(), d);
        ASSERT_EQ(a.getPerson(), p);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Account, ConstructorWrongParameters){
    bool result = true;
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Date d(2, Months::February, 2020);
    try {
        Account a("Mario", "De Simone", "IT3548D", d, -1000);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_FALSE(result);
}

TEST(Account, TestaddMoney){
    bool result = true;
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Date d(2, Months::February, 2020);
    try {
        Account a("Mario", "De Simone", "IT3548D", d, 1000);
        a.addMoney(10);
        ASSERT_EQ(a.getMoney(), 1010);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Account, TestremoveMoney){
    bool result = true;
    std::pair<std::string, std::string> p;
    p.first = "De Simone";
    p.second = "Mario";
    Date d(2, Months::February, 2020);
    try {
        Account a("Mario", "De Simone", "IT3548D", d, 1000);
        a.removeMoney(10);
        ASSERT_EQ(a.getMoney(), 990);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Account, TestinsertTransaction){
    bool result = true;
    Date d(2, Months::February, 2020);
    try {
        Account first("Mario", "De Simone", "IT3548D", d, 10);
        Account second("Napoleone", "Bonaparte", "IT3548E", d, 5);
        Transaction t(first, second, d, 4);
        first.insertTransaction(t);
        second.insertTransaction(t);
        ASSERT_EQ(*first.getTransactions().back(), t);
        ASSERT_EQ(*second.getTransactions().back(), t);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
    result = true;
    try {
        Account first("Mario", "De Simone", "IT3548D", d, 10);
        Account second("Napoleone", "Bonaparte", "IT3548E", d, 5);
        Account third("Federico", "Rapini", "IT3548F", d, 15);
        Transaction u(first, second, d, 4);
        Transaction t(first, third, d, 4);
        second.insertTransaction(u);
        second.insertTransaction(t);
        ASSERT_EQ(*second.getTransactions().back(), u);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}