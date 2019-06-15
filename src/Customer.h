#include <utility>

// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

class Customer {
    friend std::ostream &operator<<(std::ostream &result, Customer &c);

public:
    Customer();

    explicit Customer(std::string name);

    void addRental(const Rental &arg);

private:
    int frequentRenterPoints;
    std::string _name;
    std::vector<Rental> _rentals;
    double amount = 0;
};

std::ostream &operator<<(std::ostream &result, Customer &c) { //ici
    result << "Rental Record for " << c._name << "\n";
    for (Rental r: c._rentals) {
        r.applicateBonusAndCalculatePrice(result, c.frequentRenterPoints, c.amount);
    }
    // add footer lines
    result << "Amount owed is " << c.amount << "\n" << "You earned " << c.frequentRenterPoints
           << " frequent renter points";
    return result;
}

inline Customer::
Customer() {}

inline Customer::Customer(std::string name) : _name(std::move(name)), frequentRenterPoints(0) {}

inline void Customer::addRental(const Rental &arg) { _rentals.push_back(arg); }

#endif // CUSTOMER_H