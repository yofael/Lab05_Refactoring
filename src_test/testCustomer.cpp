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

class MockMovieRegular : public Regular {
public:
    MOCK_CONST_METHOD2(incrementPrice, double(double& thisAmount, int dayOfRental));
};

class MockMovieNewRelease : public New_Release {
public:
    MOCK_CONST_METHOD2(incrementPrice, double(double& thisAmount, int dayOfRental));
    MOCK_CONST_METHOD1(incrementFrequentRenterPoint, void(int& frp));
};
class MockMovieChildrens : public Childrens {
public:
    MOCK_CONST_METHOD2(incrementPrice, double(double& thisAmount, int dayOfRental));
};
class MockMovieMovie: public Movie {
public:
    MOCK_CONST_METHOD1(incrementFrequentRenterPoint, void(int& frp));
    MOCK_CONST_METHOD3(calculatePrice, std::ostream&(std::ostream& out, double& amount, int daysRental));

};

class MockMovieRental: public Rental {
public:
    MOCK_CONST_METHOD3(applicateBonusAndCalculatePrice, std::ostream&(std::ostream&, int& frp, double& amount));
};


TEST(CustomsTest, testIntergrationCustomer) {
    Customer customer("Olivier");
    customer.addRental( Rental( new Regular("Karate Kid"), 7));
    customer.addRental( Rental( new New_Release( "Avengers: Endgame"), 5));
    customer.addRental( Rental( new Childrens("Snow White"), 3 ));

    const char* s3 = "Rental Record for Olivier\n"
                     "\tKarate Kid\t9.5\n"
                     "\tAvengers: Endgame\t15\n"
                     "\tSnow White\t1.5\n"
                     "Amount owed is 26\n"
                     "You earned 4 frequent renter points";

    std::ostringstream result;
    result << customer;

    std::cout << customer << std::endl << s3 << std::endl;

    ASSERT_STREQ(s3, result.str().c_str());
}

TEST(CustomsTest, TestapplicateBonusAndCalculatePrice) {
    MockMovieChildrens childrens;
    MockMovieNewRelease release;
    MockMovieRegular regular;

    Rental r1(&childrens,7);
    Rental r2(&release,7);
    Rental r3(&regular,7);
    EXPECT_CALL(release, incrementFrequentRenterPoint(testing::_)).Times(testing::AtLeast(1));
    EXPECT_CALL(release, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));
    EXPECT_CALL(childrens, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));
    EXPECT_CALL(regular, incrementPrice(testing::_, testing::_)).Times(testing::AtLeast(1));

    std::ostringstream os;
    double d = 10;
    int i = 10;
    r1.applicateBonusAndCalculatePrice(os, i, d);
    r2.applicateBonusAndCalculatePrice(os, i, d);
    r3.applicateBonusAndCalculatePrice(os, i, d);
}

TEST(CustomsTest, testAddRental) {

    MockMovieRental r1;
    MockMovieRental r2;
    MockMovieRental r3;
    MockMovieRental r4;
    MockMovieRental r5;

    Customer c("Mock");

    c.addRental(r1);
    c.addRental(r2);
    c.addRental(r3);
    c.addRental(r4);
    c.addRental(r5);
}

TEST(customsTest, testMovieRegularIncrementPruce) {
    Regular r("Regular");

    double amount = 0;

    r.incrementPrice(amount, 3);

    ASSERT_EQ(3.5, amount);
}

TEST(customsTest, testMovieRegularIncrementFRP) {
    New_Release r("New Release");

    int frp = 6;

    r.incrementFrequentRenterPoint(frp);

    ASSERT_EQ(8, frp);
}

TEST(customsTest, testMovieChildrenIncrementPruce) {
    Childrens r("Children");

    double amount = 0;

    r.incrementPrice(amount, 4);

    ASSERT_EQ(3, amount);
}

TEST(customsTest, testMovieNewReleaseIncrementPruce) {
    New_Release r("New Release");

    double amount = 0;

    r.incrementPrice(amount, 3);

    ASSERT_EQ(9, amount);
}

TEST(customsTest, testMovieMovieCalculatePrice) {
    New_Release r("New Release");


    std::ostringstream out;
    double amount = 0;

    r.calculatePrice(out, amount, 10);

    std::string s1 = "\tNew Release\t30\n";

    ASSERT_STREQ(s1.c_str(), out.str().c_str());

}