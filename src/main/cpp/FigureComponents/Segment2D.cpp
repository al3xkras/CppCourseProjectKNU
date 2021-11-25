#include <memory>
#include "Segment2D.h"
#include "cmath"
#include "iostream"

Segment2D::Segment2D(Point2D a, Point2D b) : a(a), b(b) {}

double Segment2D::angleWithPoint(Point2D point) {
    Point2D lineVector1(b.getX() - a.getX(), b.getY() - a.getY());
    Point2D lineVector2(point.getX() - a.getX(), point.getY() - a.getY());

    double det = (lineVector1.getX()*lineVector2.getY()-lineVector2.getX()*lineVector1.getY());

    det = (det<=0)?1.0:-1.0;

    double cosine = lineVector1.dotWith(lineVector2)/(a.distanceTo(b)+a.distanceTo(point));
    double angle = acos(cosine);

    return det*angle;
}


Point2D* segmentIntersection(Segment2D &segment1, Segment2D &segment2) {
    auto* retval = (Point2D*)malloc(sizeof(Point2D));
    if (segment1==segment2){
        *retval = segment1.getA();
        //std::cout<<"Intersection: "<<*retval<<std::endl;
        return retval;
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

    *retval = Point2D(DBL_MIN,DBL_MIN);
    if ((long)(determinant*1000) == 0L) {
        //std::cout<<"det = 0: "<<*retval<<std::endl;
        return retval;
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        *retval = Point2D(x, y);

        //std::cout<<"Point: "<<*retval<<std::endl;
        //std::cout<<"i1: "<<segment1<<segment1.containsPoint(*retval)<<std::endl;
        //std::cout<<"i2: "<<segment2<<segment2.containsPoint(*retval)<<std::endl;

        if (!segment1.containsPoint(*retval) ||
            !segment2.containsPoint(*retval)){
            *retval = Point2D(DBL_MIN,DBL_MIN);

            return retval;
        }

        //std::cout<<"Intersection: "<<*retval<<std::endl;
        return retval;
    }
}

Point2D* Segment2D::intersection(AbstractLine* line) {
    auto* line2D = dynamic_cast<Line2D*>(line);
    if (line2D){
        //std::cout<<"abstract line is line"<<std::endl;
        Vector2D vector = (*line2D).getLineVector();

        double x_min = std::min(a.getX(),b.getX());
        double x_max = std::max(a.getX(),b.getX());

        Point2D p1(x_min,(*line2D)(x_min));
        Point2D p2(x_max,(*line2D)(x_max));

        //std::cout<<vector<<p1<<p2<<std::endl<<std::endl;

        Segment2D lineSegment = Segment2D(p1,p2);
        //std::cout<<lineSegment<<std::endl;
        Point2D *point2D = segmentIntersection(*this,lineSegment);
        return point2D;
    }

    auto* segment2D = dynamic_cast<Segment2D*>(line);

    if (segment2D){
        //std::cout<<"abstract line is segment"<<std::endl;
        Point2D* point2D = segmentIntersection(*this,*segment2D);
        return point2D;
    }
    throw std::runtime_error("Bad cast (Segment2D.cpp, line 42)");
}


bool Segment2D::containsPoint(Point2D& point){
    if (point==a || point==b) return true;
    long v_1_x = (long)((a.getX()-b.getX())*10000);
    long v_1_y = (long)((a.getY()-b.getY())*10000);
    long v_2_x = (long)((a.getX()-point.getX())*10000);
    long v_2_y = (long)((a.getY()-point.getY())*10000);

    //std::cout<<v_1_x<<' '<<v_1_y<<' '<<v_2_x<<' '<<v_2_y<<std::endl;
    if (v_1_x==0){
        if (v_2_x!=0) return false;
        if (v_1_y==0 && v_2_y==0) return true;
        return (long)((double)v_1_y/v_2_y)>0;
    }

    if (v_1_y==0){
        if (v_2_y!=0) return false;
        return (long)((double)v_1_x/v_2_x)>0;
    }

    long v1 = (long)((double)v_1_x/v_2_x),
         v2 = (long)((double)v_1_y/v_2_y);

    //std::cout<<'('<<v1<<' '<<v2<<')'<<std::endl;
    return (v1 == v2 & v1>0 & v2>0);
}

std::ostream &operator<<(std::ostream &os, const Segment2D &line) {
    os << "Segment( a: " << line.a << " b: " << line.b<<" )";
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

Segment2D::~Segment2D(){
    //std::cout<<*this<<" was deleted"<<std::endl;
}
