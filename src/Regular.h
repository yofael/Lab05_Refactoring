//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_REGULAR_H
#define LAB05_REGULAR_H


#include "Movie.h"
#include "Rental.h"

class Regular : public Movie {

public:
    Regular(const std::string& title);
    static const int REGULAR     = 0;
    void incrementPrice(double& thisAmount, Rental* each) const;
};

inline  Regular::
Regular(const std::string &title)
: Movie(title)
{}


inline void Regular::
incrementPrice(double& thisAmount, Rental* each ) const {
    thisAmount += 2;
    if ( each->getDaysRented() > 2 )
        thisAmount += ( each->getDaysRented() - 2 ) * 1.5 ;
}

#endif //LAB05_REGULAR_H
