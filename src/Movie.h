// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <sstream>

class Movie {
public:
    Movie(const std::string &);
    Movie();
    virtual double incrementPrice(double& amount, int dayOfRental) const = 0;
    virtual void incrementFrequentRenterPoint(int& frp) const;
    std::ostringstream & afficher(std::ostringstream& out, double& amount, int daysRental) const;
private:
    std::string _title;
};

inline Movie::
Movie() {}

inline Movie::
Movie(const std::string& title)
        : _title( title )
{}
inline void Movie::
incrementFrequentRenterPoint(int &frp) const {
    ++frp;
}

inline std::ostringstream& Movie::afficher(std::ostringstream& out, double& amount, int daysRental) const {
    out << "\t" << _title << "\t"
            << incrementPrice(amount, daysRental) << "\n";
    return out;
}
#endif // MOVIE_H