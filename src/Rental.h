// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:
    Rental();

    Rental(const Movie *movie, int daysRented);

    std::ostream &applicateBonusAndCalculatePrice(std::ostream &result, int &frp, double &amount);

private:
    const Movie *_movie;
    int _daysRented;
};


inline Rental::
Rental() {}

inline Rental::
Rental(const Movie *movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}


inline std::ostream &Rental::applicateBonusAndCalculatePrice(std::ostream &result, int &frp, double &amount) {
    _movie->incrementFrequentRenterPoint(frp);

    return _movie->calculatePrice(result, amount, _daysRented);
}

#endif // RENTAL_H