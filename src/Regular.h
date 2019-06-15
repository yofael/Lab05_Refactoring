//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_REGULAR_H
#define LAB05_REGULAR_H


#include "Movie.h"

class Regular : public Movie {

public:
    Regular();
    Regular(const std::string& title);
    double incrementPrice(double& amount, int dayOfRental) const;
};

inline  Regular::
Regular(const std::string &title)
: Movie(title)
{}

inline  Regular::
Regular()
{}
inline double Regular::
incrementPrice(double& amount, int dayOfRental ) const {
    double thisAmount = 2;
    if ( dayOfRental > 2 )
        thisAmount += ( dayOfRental - 2 ) * 1.5 ;
    amount += thisAmount;
    return thisAmount;
}

#endif //LAB05_REGULAR_H
