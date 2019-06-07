//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_CHILDRENS_H
#define LAB05_CHILDRENS_H

#include "Movie.h"

class Childrens : public Movie {

public:
    Childrens();
    Childrens(const std::string& title);
    static const int CHILDRENS   = 2;
    void incrementPrice(double& thisAmount, int dayOfRental) const;

};

inline  Childrens::
Childrens(const std::string &title)
: Movie(title)
{}


inline  Childrens::
Childrens()
{}


inline void Childrens::
incrementPrice(double& thisAmount, int dayOfRental) const {
    thisAmount += 1.5;
    if ( dayOfRental > 3 )
        thisAmount += ( dayOfRental - 3 ) * 1.5;
}

#endif //LAB05_CHILDRENS_H
