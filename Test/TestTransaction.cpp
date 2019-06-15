//
// Created by Mario De Simone on 2019-06-14.
//
#include "gtest/gtest.h"

#include "../Transaction.h"
#include "../Account.h"

TEST(Transaction, ConstructorDefaultParameters){
    Date d(1, 1, 2020);
    Account first("Mario", "De Simone", d, 10);
    Account second("Napoleone", "Bonaparte", d, 5);
    Transaction t(first, second);
    ASSERT_EQ(first.getMoney(), 10);
    ASSERT_EQ(second.getMoney(), 5);
    ASSERT_EQ(t.getAmount(), 0);
    ASSERT_EQ(t.getDateTransaction(), Date());
    ASSERT_EQ(t.getType(), Category::other);
    ASSERT_EQ(t.getBeneficiary(), "Bonaparte Napoleone");
    ASSERT_EQ(t.getPayer(), "De Simone Mario");
}

TEST(Transaction, ConstructorWrongParameters){
    Date d(2, 2, 2020);
    Account first("Mario", "De Simone", d, 10);
    Account second("Napoleone", "Bonaparte", d, 5);
    Transaction t(first, second, d, -1);
    ASSERT_EQ(first.getMoney(), 10);
    ASSERT_EQ(second.getMoney(), 5);
    ASSERT_EQ(t.getAmount(), 0);
    ASSERT_EQ(t.getDateTransaction(), d);
    ASSERT_EQ(t.getType(), Category::other);
    ASSERT_EQ(t.getBeneficiary(), "Bonaparte Napoleone");
    ASSERT_EQ(t.getPayer(), "De Simone Mario");
}

TEST(Transaction, TestEqualityOperator){
    Account first("Mario", "De Simone", Date(), 10);
    Account second("Napoleone", "Bonaparte", Date(), 5);
    Transaction t(first, second, Date(), -1);
    Transaction u(first, second, Date(), 0);
    ASSERT_EQ(t, u);
}