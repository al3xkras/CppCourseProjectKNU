#ifndef CPPCOURSEPROJECTKNU_POLYLINE2D_H
#define CPPCOURSEPROJECTKNU_POLYLINE2D_H


#include "Point2D.h"

class Polyline2D {
private:
    size_t points_size;
    Point2D* points;
public:
    Polyline2D(Point2D *points, size_t pointsSize);

    virtual ~Polyline2D();
};


#endif //CPPCOURSEPROJECTKNU_POLYLINE2D_H
