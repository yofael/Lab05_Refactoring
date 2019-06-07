//
// Created by Rafael Garcia on 2019-05-17.
//

#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <iostream>
#include <cstring>
#include <string>

#include "../src/Customer.h"
#include "../src/Childrens.h"
#include "../src/New_Release.h"
#include "../src/Regular.h"

class MockCustomer : public Customer {
public:
    MOCK_METHOD1(addRental, void(const Rental& arg));
    MOCK_CONST_METHOD0(getName, std::string());
    MOCK_METHOD0(statement, std::string());
};

class MockMovieRegular : public Regular {
public:
    MOCK_CONST_METHOD2(incrementPrice, void(double& thisAmount, int dayOfRental));
    MOCK_CONST_METHOD1(incrementFrequentRenterPoint, void(int& frp));
    MOCK_CONST_METHOD0(getTitle, std::string());
};

class MockMovieNewRelease : public New_Release {
public:
    MOCK_CONST_METHOD2(incrementPrice, void(double& thisAmount, int dayOfRental));
    MOCK_CONST_METHOD1(incrementFrequentRenterPoint, void(int& frp));
    MOCK_CONST_METHOD0(getTitle, std::string());
};
class MockMovieChildrens : public Childrens {
public:
    MOCK_CONST_METHOD2(incrementPrice, void(double& thisAmount, int dayOfRental));
    MOCK_CONST_METHOD1(incrementFrequentRenterPoint, void(int& frp));
    MOCK_CONST_METHOD0(getTitle, std::string());
};
TEST(CustomsTest, TestDeStatement) {
    Customer customer("Olivier");
    customer.addRental( Rental( new Regular("Karate Kid"), 7));
    customer.addRental( Rental( new New_Release( "Avengers: Endgame"), 5));
    customer.addRental( Rental( new Childrens("Snow White"), 3 ));

    const char* s1 = customer.statement().c_str();

    const char* s3 = "Rental Record for Olivier\n"
                     "\tKarate Kid\t9.5\n"
                     "\tAvengers: Endgame\t15\n"
                     "\tSnow White\t1.5\n"
                     "Amount owed is 26\n"
                     "You earned 4 frequent renter points";

    ASSERT_STREQ(s1, s3);
}

TEST(CustomsTest, TestDeRegularIncrementPrice) {
    MockMovieRegular mm;
    EXPECT_CALL(mm, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeRegularIncrementFRP) {
    MockMovieRegular mm;
    EXPECT_CALL(mm, incrementFrequentRenterPoint(testing::_)).Times(testing::AtLeast(5));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeRegularGetTitle) {
    MockMovieRegular mm;
    EXPECT_CALL(mm, getTitle()).Times(testing::AtLeast(3));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeNewReleaseIncrementPrice) {
    MockMovieNewRelease mm;
    EXPECT_CALL(mm, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeNewReleaseIncrementFRP) {
    MockMovieNewRelease mm;
    EXPECT_CALL(mm, incrementFrequentRenterPoint(testing::_)).Times(testing::AtLeast(5));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeNewReleaseGetTitle) {
    MockMovieNewRelease mm;
    EXPECT_CALL(mm, getTitle()).Times(testing::AtLeast(3));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeChildrensIncrementPrice) {
    MockMovieChildrens mm;
    EXPECT_CALL(mm, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeChildrensIncrementFRP) {
    MockMovieChildrens mm;
    EXPECT_CALL(mm, incrementFrequentRenterPoint(testing::_)).Times(testing::AtLeast(5));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}

TEST(CustomsTest, TestDeChildrensGetTitle) {
    MockMovieChildrens mm;
    EXPECT_CALL(mm, getTitle()).Times(testing::AtLeast(3));
    Customer c("Olivier");
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.addRental(Rental(&mm, 7));
    c.statement();
}