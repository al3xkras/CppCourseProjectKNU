#ifndef CPPCOURSEPROJECTKNU_LINE_H
#define CPPCOURSEPROJECTKNU_LINE_H


#include <ostream>
#include "Point2D.h"
#include "Line2D.h"
#include "abstract/AbstractLine.h"

class Segment2D: public AbstractLine{
private:
    Point2D a;
    Point2D b;
public:
    Segment2D(): a(), b() {};

    Segment2D(Point2D a, Point2D b);
    double angleWithPoint(Point2D point);

    Point2D* intersection(AbstractLine* other) override;

    bool containsPoint(Point2D& point);

    friend std::ostream &operator<<(std::ostream &os, const Segment2D &line);

    bool operator==(const Segment2D &rhs) const;

    bool operator!=(const Segment2D &rhs) const;

    const Point2D &getA() const;
    const Point2D &getB() const;

    virtual ~Segment2D();
};


#endif //CPPCOURSEPROJECTKNU_LINE_H
