#include "Polyline2D.h"
#include "iostream"
Polyline2D::Polyline2D(Point2D* points, size_t points_size) {
    this->segments = std::vector<Segment2D>();
    this->points_size=points_size;

    for (int i=0; i<points_size-1; i++){
        Segment2D segment2D(points[i],points[i+1]);

        segments.push_back(segment2D);
    }
}

Polyline2D::~Polyline2D() = default;

bool Polyline2D::hasSelfIntersections() {
    Point2D notAPoint = Point2D(DBL_MIN, DBL_MIN);

    //O(n*ln(n))
    for (int i=0; i<segments.size(); i++){
        for (int j=0; j<segments.size(); j++){
            if (i==j) continue;

            Point2D intersection = segments[i].intersection(segments[j]);

            if (intersection == notAPoint ||
                    (j == i+1 && intersection == segments[i].getB()) ||
                    (i == j+1 && intersection == segments[j].getB())){
                continue;
            }
            std::cout<<intersection<<std::endl;
            return true;
        }
    }

    return false;
}

std::ostream &operator<<(std::ostream &os, const Polyline2D &d) {
    os << "PolyLine2D: {";
    for (const Segment2D& segment: d.segments){
        os<<segment<<',';
    }
    os<<"}";
    return os;
}
