#include "Segment2D.h"
#include "cmath"
#include "iostream"

Segment2D::Segment2D(Point2D &a, Point2D &b) : a(a), b(b) {}

double Segment2D::angleWithPoint(Point2D point) {
    Point2D lineVector1(b.getX() - a.getX(), b.getY() - a.getY());
    Point2D lineVector2(point.getX() - a.getX(), point.getY() - a.getY());

    double det = (lineVector1.getX()*lineVector2.getY()-lineVector2.getX()*lineVector1.getY());

    det = (det<=0)?1.0:-1.0;

    double cosine = lineVector1.dotWith(lineVector2)/(a.distanceTo(b)+a.distanceTo(point));
    double angle = acos(cosine);

    return det*angle;
}


Point2D& segmentIntersection(Segment2D &segment1, Segment2D &segment2) {
    if (segment1==segment2){
        return const_cast<Point2D &>(segment1.getA());
    }

    const Point2D& C = segment2.getA();
    const Point2D& D = segment2.getB();

    double a1 = segment1.getB().getY() - segment1.getA().getY();
    double b1 = segment1.getA().getX() - segment1.getB().getX();
    double c1 = a1 * (segment1.getA().getX()) + b1 * (segment1.getA().getY());

    double a2 = D.getY() - C.getY();
    double b2 = C.getX() - D.getX();
    double c2 = a2 * (C.getX()) + b2 * (C.getY());

    double determinant = a1 * b2 - a2 * b1;

    Point2D* point = nullptr;

    if ((long)(determinant*1000) == 0L) {
        return *point;
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        *point = Point2D(x, y);

        if (!segment1.containsPoint(*point) ||
            !segment2.containsPoint(*point)){
            return *point;
        }

        return *point;
    }
}

Point2D& Segment2D::intersection(AbstractLine* line) {
    auto* line2D = dynamic_cast<Line2D*>(line);

    if (line2D){
        Vector2D vector = (*line2D).getLineVector();

        double x_min = std::min(a.getX(),b.getX());

        Point2D p1(x_min,(*line2D).getH());
        Point2D p2(x_min+vector.getX(), (*line2D).getH()+ vector.getY());

        Segment2D lineSegment = Segment2D(p1,p2);

        return segmentIntersection(*this,lineSegment);
    }

    auto* segment2D = dynamic_cast<Segment2D*>(line);

    if (segment2D){
        return segmentIntersection(*this,*segment2D);
    }
    std::cout<<"Bad cast (Segment2D.cpp, line 42)";
    throw std::bad_cast();
}


bool Segment2D::containsPoint(Point2D point){
    long v_1_x = (long)((a.getX()-b.getX())*10000);
    long v_1_y = (long)((a.getY()-b.getY())*10000);
    long v_2_x = (long)((a.getX()-point.getX())*10000);
    long v_2_y = (long)((a.getY()-point.getY())*10000);

    long v1 = (long)((double)v_1_x/v_2_x),
         v2 = (long)((double)v_1_y/v_2_y);

    return (v1 == v2 & v1>0 & v2>0);
}

std::ostream &operator<<(std::ostream &os, const Segment2D &line) {
    os << "a: " << line.a << " b: " << line.b;
    return os;
}

const Point2D &Segment2D::getA() const {
    return a;
}

const Point2D &Segment2D::getB() const {
    return b;
}

bool Segment2D::operator==(const Segment2D &rhs) const {
    return a == rhs.a && b == rhs.b;
}

bool Segment2D::operator!=(const Segment2D &rhs) const {
    return !(rhs == *this);
}

Segment2D::~Segment2D() = default;
