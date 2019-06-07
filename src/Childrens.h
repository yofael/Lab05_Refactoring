//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_CHILDRENS_H
#define LAB05_CHILDRENS_H


#include "Movie.h"
#include "Rental.h"

class Childrens : public Movie {

public:
    Childrens(const std::string& title);
    static const int CHILDRENS   = 2;
    void incrementPrice(double& thisAmount, Rental* each) const;

};

inline  Childrens::
Childrens(const std::string &title)
: Movie(title)
{}


inline void Childrens::
incrementPrice(double& thisAmount, Rental* each) const {
    thisAmount += 1.5;
    if ( each->getDaysRented() > 3 )
        thisAmount += ( each->getDaysRented() - 3 ) * 1.5;
}

#endif //LAB05_CHILDRENS_H
