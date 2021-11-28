#ifndef CPPCOURSEPROJECTKNU_POINT_H
#define CPPCOURSEPROJECTKNU_POINT_H


#include <ostream>
#include "abstract/AbstractPoint.h"



struct Point2D: public AbstractPoint {
private:
    double x;
    double y;
public:
    Point2D(): x(DBL_MIN), y(DBL_MIN){};
    Point2D(const Point2D &p) {
        this->x = p.x;
        this->y = p.y;
    }
    Point2D(double x, double y);
    double getCoordinate(int index) override;

    double dotWith(Point2D other);
    double distanceTo(Point2D other);

    double getX() const;
    double getY() const;
    void setX(double X);
    void setY(double Y);

    bool operator==(const Point2D &rhs) const;

    bool operator!=(const Point2D &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Point2D &point);

    virtual ~Point2D();
};


#endif //CPPCOURSEPROJECTKNU_POINT_H
