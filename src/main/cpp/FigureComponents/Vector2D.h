#ifndef CPPCOURSEPROJECTKNU_VECTOR2D_H
#define CPPCOURSEPROJECTKNU_VECTOR2D_H


#include <ostream>

class Vector2D {
private:
    double x1;
    double x2;
public:
    Vector2D(double x1, double x2);

    bool operator==(const Vector2D &rhs) const;
    bool operator!=(const Vector2D &rhs) const;
    Vector2D &operator+(const Vector2D &other) const;
    double operator*(const Vector2D &other) const;

    double getX() const;
    double getY() const;

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &d);
};


#endif //CPPCOURSEPROJECTKNU_VECTOR2D_H
