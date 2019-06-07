// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
    Movie(const std::string &);

    virtual void incrementPrice(double& thisAmount, int dayOfRental) const = 0;
    virtual void incrementFrequentRenterPoint(int& frp) const;
    std::string getTitle() const;

private:
    std::string _title;
};

inline Movie::
Movie(const std::string& title)
        : _title( title )
{}
inline void Movie::
incrementFrequentRenterPoint(int &frp) const {

}
inline std::string Movie::
getTitle() const { return _title; }


#endif // MOVIE_H