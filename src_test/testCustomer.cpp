//
// Created by Rafael Garcia on 2019-05-17.
//

#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <string>

#include "../src/Customer.h"

TEST(CustomsTest, essai) {
    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    Customer customer2("Olivier");
    customer2.addRental( Rental( Movie("Karate Kid"), 7));
    customer2.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer2.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    const char* s1 = customer.statement().c_str();
    const char* s2 = customer2.statement().c_str();

    ASSERT_STREQ(s1, s2);
}