#ifndef CPPCOURSEPROJECTKNU_POLYLINE2D_H
#define CPPCOURSEPROJECTKNU_POLYLINE2D_H


#include <vector>
#include <ostream>
#include "Point2D.h"
#include "Segment2D.h"

class Polyline2D {
private:
    size_t points_size;
    std::vector<Segment2D> segments;
public:

    Polyline2D(Point2D *points, size_t pointsSize);

    bool hasSelfIntersections();

    std::vector<Segment2D> &getSubSegments(){
        return this->segments;
    };

    friend std::ostream &operator<<(std::ostream &os, const Polyline2D &d);

    virtual ~Polyline2D();
};


#endif //CPPCOURSEPROJECTKNU_POLYLINE2D_H
