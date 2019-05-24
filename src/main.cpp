#include <iostream>

#include "Customer.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << customer.statement() << std::endl;

    Customer customer2("Olivier");
    customer2.addRental( Rental( Movie("Karate Kid"), 7));
    customer2.addRental( Rental( Movie( "Avengers: Endgame", Movie::NEW_RELEASE ), 5));
    customer2.addRental( Rental( Movie("Snow White", Movie::CHILDRENS), 3 ));

    std::cout << customer2.statement() << std::endl;
    return 0;
}