#include "Vector2D.h"

Vector2D::Vector2D(double x1, double x2) {
    this->x1=x1;
    this->x2=x2;
}

bool Vector2D::operator==(const Vector2D &rhs) const {
    return x1 == rhs.x1 &&
           x2 == rhs.x2;
}

bool Vector2D::operator!=(const Vector2D &rhs) const {
    return !(rhs == *this);
}

double Vector2D::getX() const {
    return x1;
}

double Vector2D::getY() const {
    return x2;
}

Vector2D &Vector2D::operator+(const Vector2D &other) const {
    Vector2D vector = Vector2D(x1+ other.getX(), x2 + other.getY());
    return vector;
}

double Vector2D::operator*(const Vector2D &other) const {
    return (x1* other.getX() + x2 * other.getY());
}
