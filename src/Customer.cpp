// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;
using namespace std;

string Customer::statement()
{
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        Rental each = *iter;

        // add bonus for a two day new release rental
        each.getMovie()->incrementFrequentRenterPoint(frequentRenterPoints);

        // show figures for this rental
        each.getMovie()->afficher(result, amount, each.getDaysRented());
    }
    // add footer lines
    return this->afficher(result).str();
}


std::ostringstream& Customer::afficher(std::ostringstream& out) {
    out << "Amount owed is " << amount << "\n" << "You earned " << frequentRenterPoints << " frequent renter points";
    return out;
}