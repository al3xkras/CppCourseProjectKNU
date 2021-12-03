#include "Triangle2D.h"
#include "cmath"

Triangle2D::Triangle2D(const Point2D &a, const Point2D &b, const Point2D &c): points(3){
    points[0] = a;
    points[1] = b;
    points[2] = c;
}

Triangle2D::~Triangle2D() {

}

TriangleEdgesLength Triangle2D::getEdgesLength() const {
    double AB = points[0].distanceTo(points[1]);
    double BC = points[1].distanceTo(points[2]);
    double AC = points[0].distanceTo(points[2]);

    TriangleEdgesLength length = TriangleEdgesLength(AB,BC,AC);
    return length;
}

double Triangle2D::area() {
    TriangleEdgesLength length = getEdgesLength();
    double p = (length.getAb()+length.getBc()+length.getAc())/2;
    return sqrt(p*(p-length.getAb())*(p-length.getBc())*(p-length.getAc()));
}

double Triangle2D::p() const{
    TriangleEdgesLength length = getEdgesLength();
    return (length.getAb()+length.getBc()+length.getAc());
}


bool Triangle2D::isConvex() {
    if (area()!=0){
        return true;
    }
    return false;
}

std::ostream &Triangle2D::toString(std::ostream &os) {
    os << "Triangle2D: ";
    for (const Point2D& p: points){
        os<<'('<<p<<"), ";
    }
    return os;
}

bool Triangle2D::operator>(const Triangle2D &rhs) const{
    return rhs < *this;
}

bool Triangle2D::operator<=(const Triangle2D &rhs) const{
    return !(rhs < *this);
}

bool Triangle2D::operator>=(const Triangle2D &rhs) const{
    return !(*this < rhs);
}

TriangleEdgesLength::TriangleEdgesLength(double ab, double bc, double ac) : AB(ab), BC(bc), AC(ac) {}

double TriangleEdgesLength::getAb() const {
    return AB;
}

double TriangleEdgesLength::getBc() const {
    return BC;
}

double TriangleEdgesLength::getAc() const {
    return AC;
}

std::ostream &operator<<(std::ostream &os, const TriangleEdgesLength &length) {
    os << "AB: " << length.AB << " BC: " << length.BC << " AC: " << length.AC;
    return os;
}
