//
// Created by Rafael Garcia on 2019-05-17.
//

#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <string>

#include "../src/Customer.h"
#include "../src/Childrens.h"
#include "../src/New_Release.h"
#include "../src/Regular.h"

TEST(CustomsTest, essai) {
    Customer customer("Olivier");
    customer.addRental( Rental( new Regular("Karate Kid"), 7));
    customer.addRental( Rental( new New_Release( "Avengers: Endgame"), 5));
    customer.addRental( Rental( new Childrens("Snow White"), 3 ));

    const char* s1 = customer.statement().c_str();

    std::cout << s1 << std::endl;
/*
    const char* s3 = "Rental Record for Olivier\n"
                     "\tKarate Kid\t9.5\n"
                     "\tAvengers: Endgame\t15\n"
                     "\tSnow White\t1.5\n"
                     "Amount owed is 26\n"
                     "You earned 4 frequent renter points";

    ASSERT_STREQ(s1, s3);*/
}