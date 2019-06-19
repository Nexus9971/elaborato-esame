//
// Created by Mario De Simone on 2019-06-14.
//
#include "gtest/gtest.h"
#include "../Transaction.h"
#include "../Account.h"
#include <utility>
#include <stdexcept>

TEST(Transaction, ConstructorRightParameters){
    bool result = true;
    Date d(1, Months::January, 2020);
    Account first("Mario", "De Simone", "IT3548D", d, 10);
    Account second("Napoleone", "Bonaparte", "IT3548E", d, 5);
    std::pair<std::string, std::string> id = std::make_pair(first.getId(), second.getId());
    try {
        Transaction t(first, second, d, 1);
        ASSERT_EQ(first.getMoney(), 9);
        ASSERT_EQ(second.getMoney(), 6);
        ASSERT_EQ(t.getAmount(), 1);
        ASSERT_EQ(t.getId(), id);
        ASSERT_EQ(t.getDateTransaction(), d);
        ASSERT_EQ(t.getType(), Category::other);
        ASSERT_EQ(t.getBeneficiary(), "Bonaparte Napoleone");
        ASSERT_EQ(t.getPayer(), "De Simone Mario");
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Transaction, ConstructorWrongParameters){
    bool result = true;
    Date d(2, Months::February, 2020);
    Account first("Mario", "De Simone", "IT3548D", d, 10);
    Account second("Napoleone", "Bonaparte", "IT3548E", d, 5);
    try {
        Transaction t(first, second, d, -1);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_FALSE(result);
}

TEST(Transaction, TestEqualityOperator){
    Date d(2, Months::February, 2020);
    Account first("Mario", "De Simone", "IT3548D", d, 10);
    Account second("Napoleone", "Bonaparte", "IT3548E", d, 5);
    Transaction t(first, second, d, 2);
    Transaction u(first, second, d, 2);
    ASSERT_EQ(t, u);
    Transaction v(first, second, d, 1);
    ASSERT_FALSE(v==u);
}