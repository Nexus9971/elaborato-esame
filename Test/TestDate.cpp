//
// Created by Mario De Simone on 2019-06-14.
//

#include "gtest/gtest.h"

#include "../Date.h"

TEST(Date, ConstructorDefaultParameters){
    Date d;
    ASSERT_EQ(d.getDay(), 1);
    ASSERT_EQ(d.getMonth(), 1);
    ASSERT_EQ(d.getYear(), 2019);
}

TEST(Date, ConstructorWrongParameters){
    Date d(0, -1, 1999);
    ASSERT_EQ(d.getDay(), 1);
    ASSERT_EQ(d.getMonth(), 1);
    ASSERT_EQ(d.getYear(), 2019);
    Date t(29, 2, 2019);
    ASSERT_EQ(t.getDay(), 1);
    ASSERT_EQ(t.getMonth(), 2);
    ASSERT_EQ(t.getYear(), 2019);
}

TEST(Date, TestEqualityOperator){
    Date t(1, 1, 2019);
    Date d(0, -1, 1999);
    ASSERT_EQ(t, d);
}