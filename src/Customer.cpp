// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;
using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    vector< Rental >::iterator iter = _rentals.begin();
    vector< Rental >::iterator iter_end = _rentals.end();
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for ( ; iter != iter_end; ++iter ) {
        double thisAmount = 0;
        Rental each = *iter;

        each.getMovie()->incrementPrice(thisAmount, each.getDaysRented());
        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        each.getMovie()->incrementFrequentRenterPoint(frequentRenterPoints);

        // show figures for this rental
        result << "\t" << each.getMovie()->getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount;
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}