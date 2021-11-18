#ifndef CPPCOURSEPROJECTKNU_LINE_H
#define CPPCOURSEPROJECTKNU_LINE_H


#include <ostream>
#include "Point2D.h"

class Line2D {
private:
    Point2D a;
    Point2D b;
public:
    Line2D(const Point2D &a, const Point2D &b);
    double angleWithPoint(Point2D point);

    friend std::ostream &operator<<(std::ostream &os, const Line2D &line);
};


#endif //CPPCOURSEPROJECTKNU_LINE_H
