// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
//#include "Rental.h"
class Rental;
class Movie {
public:
    Movie(const std::string &);

    virtual void incrementPrice(double& thisAmount, Rental* each) const = 0;
    std::string getTitle() const;

private:
    std::string _title;
};

inline Movie::
Movie(const std::string& title)
        : _title( title )
{}

inline std::string Movie::
getTitle() const { return _title; }


#endif // MOVIE_H