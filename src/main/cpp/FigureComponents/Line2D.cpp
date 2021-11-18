#include "Line2D.h"
#include "cmath"

Line2D::Line2D(const Point2D &a, const Point2D &b) : a(a), b(b) {}

double Line2D::angleWithPoint(Point2D point) {
    Point2D lineVector1(b.getX() - a.getX(), b.getY() - a.getY());
    Point2D lineVector2(point.getX() - a.getX(), point.getY() - a.getY());

    double det = (lineVector1.getX()*lineVector2.getY()-lineVector2.getX()*lineVector1.getY());

    det = (det<=0)?1.0:-1.0;

    double cosine = lineVector1.dotWith(lineVector2)/(a.distanceTo(b)+a.distanceTo(point));
    double angle = acos(cosine);

    return det*angle;
}

std::ostream &operator<<(std::ostream &os, const Line2D &line) {
    os << "a: " << line.a << " b: " << line.b;
    return os;
}
