//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_NEW_RELEASE_H
#define LAB05_NEW_RELEASE_H


#include "Movie.h"
#include "Rental.h"

class New_Release : public Movie {

public:
    New_Release(const std::string& title);
    static const int NEW_RELEASE = 1;
    void incrementPrice(double& thisAmount, Rental* each) const;
};

inline  New_Release::
New_Release(const std::string &title)
        : Movie(title)
{}

inline void New_Release::
incrementPrice(double& thisAmount, Rental* each) const {
    thisAmount += each->getDaysRented() * 3;
}

#endif //LAB05_NEW_RELEASE_H
