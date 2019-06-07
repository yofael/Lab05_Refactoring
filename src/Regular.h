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
    static const int REGULAR     = 0;
    void incrementPrice(double& thisAmount, int dayOfRental) const;
};

inline  Regular::
Regular(const std::string &title)
: Movie(title)
{}

inline  Regular::
Regular()
{}
inline void Regular::
incrementPrice(double& thisAmount, int dayOfRental ) const {
    thisAmount += 2;
    if ( dayOfRental > 2 )
        thisAmount += ( dayOfRental - 2 ) * 1.5 ;
}

#endif //LAB05_REGULAR_H
