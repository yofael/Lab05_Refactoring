//
// Created by Rafael Garcia on 2019-06-07.
//

#ifndef LAB05_NEW_RELEASE_H
#define LAB05_NEW_RELEASE_H


#include "Movie.h"

class New_Release : public Movie {

public:
    New_Release();

    New_Release(const std::string &title);

    double incrementPrice(double &amount, int dayOfRental) const;

    void incrementFrequentRenterPoint(int &frp) const;

};

inline  New_Release::
New_Release(const std::string &title)
        : Movie(title) {}


inline  New_Release::
New_Release() {}


inline double New_Release::
incrementPrice(double &amount, int dayOfRental) const {
    amount += dayOfRental * 3;
    return dayOfRental * 3;
}

inline void New_Release::
incrementFrequentRenterPoint(int &frp) const {
    frp += 2;
}

#endif //LAB05_NEW_RELEASE_H
