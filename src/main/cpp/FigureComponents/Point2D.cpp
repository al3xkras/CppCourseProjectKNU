#include "cmath"
#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::getX() const {
    return x;
}

double Point2D::getY() const {
    return y;
}

void Point2D::setX(double X) {
    Point2D::x = X;
}

void Point2D::setY(double Y) {
    Point2D::y = Y;
}

double Point2D::dotWith(Point2D other) {
    double dot = getX()*other.getX()+
            getY()*other.getY();
    return dot;
}

double Point2D::distanceTo(Point2D other) {
    double dist = sqrt(
            pow(getX()-other.getX(),2)+
            pow(getY()-other.getY(),2));
    return dist;
}

std::ostream &operator<<(std::ostream &os, const Point2D &point) {
    os << "x: " << point.getX() << " y: " << point.getY();
    return os;
}