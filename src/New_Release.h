//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_NEW_RELEASE_H
#define LAB05_NEW_RELEASE_H


#include "Movie.h"

class New_Release : public Movie {

public:
    New_Release(const std::string& title);
    static const int NEW_RELEASE = 1;
    void incrementPrice(double& thisAmount, int dayOfRental) const;
    void incrementFrequentRenterPoint(int& frp) const;

};

inline  New_Release::
New_Release(const std::string &title)
        : Movie(title)
{}

inline void New_Release::
incrementPrice(double& thisAmount, int dayOfRental) const {
    thisAmount += dayOfRental * 3;
}

inline void New_Release::
incrementFrequentRenterPoint(int &frp) const {
    frp++;
}
#endif //LAB05_NEW_RELEASE_H
