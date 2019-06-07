#include <iostream>

#include "Customer.h"
#include "Regular.h"
#include "Childrens.h"
#include "New_Release.h"

int main() {

    Customer customer("Olivier");
    customer.addRental( Rental( new Regular("Karate Kid"), 7));
    customer.addRental( Rental( new New_Release( "Avengers: Endgame"), 5));
    customer.addRental( Rental( new Childrens("Snow White"), 3 ));

    std::cout << customer.statement() << std::endl;

    Customer customer2("Olivier");
    customer.addRental( Rental( new Regular("Karate Kid"), 7));
    customer.addRental( Rental( new New_Release( "Avengers: Endgame"), 5));
    customer.addRental( Rental( new Childrens("Snow White"), 3 ));

    std::cout << customer2.statement() << std::endl;
    return 0;
}