#ifndef CPPCOURSEPROJECTKNU_POINT_H
#define CPPCOURSEPROJECTKNU_POINT_H


#include <ostream>

class Point2D {
private:
    double x;
    double y;
public:
    Point2D(double x, double y);

    double dotWith(Point2D other);
    double distanceTo(Point2D other);

    double getX() const;
    double getY() const;
    void setX(double X);
    void setY(double Y);

    friend std::ostream &operator<<(std::ostream &os, const Point2D &point);
};


#endif //CPPCOURSEPROJECTKNU_POINT_H
