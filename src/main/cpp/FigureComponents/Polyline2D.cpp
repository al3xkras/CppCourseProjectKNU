#include "Polyline2D.h"

Polyline2D::Polyline2D(Point2D* points, size_t points_size) {
    this->points = points;
    this->points_size=points_size;
}

Polyline2D::~Polyline2D() {
    delete[] points;
}
