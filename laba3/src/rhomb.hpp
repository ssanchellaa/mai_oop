#ifndef RHOMB_HPP
#define RHOMB_HPP

#include "figure.hpp"

class Rhomb : public Figure {
public:
    Rhomb();
    Rhomb(Point& p_1, Point& p_2, Point& p_3, Point& p_4);
    
    virtual double getArea() const override;
    virtual operator double() const override;

    Rhomb& operator=(Rhomb& other);
    Rhomb& operator=(Rhomb&& other);
    bool operator==(const Rhomb& other);

    ~Rhomb() {
        n = 0;
        delete [] p;
        p = nullptr;
    }
};

#endif