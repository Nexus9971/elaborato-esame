//
// Created by Mario De Simone on 2019-06-14.
//

#include "gtest/gtest.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include "../Date.h"

TEST(Date, ConstructorRightParameters){
    bool result = true;
    try {
        Date d(29, Months::February, 2020);
        ASSERT_EQ(d.getDay(), 29);
        ASSERT_EQ(d.getMonth(), Months::February);
        ASSERT_EQ(d.getYear(), 2020);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Date, ConstructorWrongParameters){
    bool result = true;
    try {
        Date d(0, Months::September, -1999);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_FALSE(result);
    result = true;
    try {
        Date d(29, Months::February, 1999);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_FALSE(result);
}

TEST(Date, TestEqualityOperator){
    bool result = true;
    try {
        Date t(1, Months::January, 2019);
        Date d(1, Months::January, 2019);
        Date u(1, Months::February, 2019);
        ASSERT_EQ(t, d);
        ASSERT_FALSE(t==u);
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}

TEST(Date, TestToString){
    bool result = true;
    try {
        Date t(1, Months::January, 2019);
        std::stringstream stream;
        stream << 1 << " January " << 2019;
        ASSERT_EQ(stream.str(), t.dateToString());
    }catch(std::out_of_range& e){
        result = false;
    }
    ASSERT_TRUE(result);
}