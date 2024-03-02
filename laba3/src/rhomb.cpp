#include "rhomb.hpp"

Rhomb::Rhomb () {
    n = 4;
    p = new Point[n];
}

Rhomb::Rhomb(Point& p_1, Point& p_2, Point& p_3, Point& p_4) {
    n = 4;
    p = new Point[n];
    std::vector<Point> ar;
    ar.push_back(p_1);
    ar.push_back(p_2);
    ar.push_back(p_3);
    ar.push_back(p_4);
    for (int i = 0; i < ar.size(); i++) {
        for (int j = i + 1; j < ar.size(); j++) {
            if (ar[i].Equal(ar[j])) {
                throw std::logic_error("Points can't be simular!\n");
            }
        }
    }
    p[0] = p_1;
    p[1] = p_2;
    p[2] = p_3;
    p[3] = p_4;
}

double Rhomb::getArea() const {
    double area = 0;
    for (int i = 0; i < n; i++) {
        Point p_x = p[i];
        Point p_y = p[(i + 1) % n];
        area += p_x.x * p_y.y - p_y.x * p_x.y;
    }
    return 0.5 * abs(area);
}

bool Rhomb::operator==(const Rhomb& other) {
    return static_cast<double>(*this) == static_cast<double>(other);
}

Rhomb& Rhomb::operator=(Rhomb& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = other.p[i];
        }
        this->n = other.n;
    }
    return *this;
};

Rhomb& Rhomb::operator=(Rhomb&& other) {
    if (!(this == &other)) {
        for (int i = 0; i < 4; i++) {
            this->p[i] = std::move(other.p[i]);
        }
        this->n = other.n;
    }
    return *this;
};

Rhomb::operator double() const {
    return getArea();
}