#ifndef PENTAGON_HPP
#define PENTAGON_HPP

#include "figure.hpp"

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(Point& p_1, Point& p_2, Point& p_3, Point& p_4, Point& p_5);

    virtual double getArea() const override;
    virtual operator double() const override;

    Pentagon& operator=(Pentagon& other);
    Pentagon& operator=(Pentagon&& other);
    bool operator==(const Pentagon& other);

    ~Pentagon(){
        n = 0;
        delete [] p;
        p = nullptr;
    }
};

#endif