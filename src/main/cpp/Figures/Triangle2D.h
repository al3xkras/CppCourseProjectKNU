#ifndef CPPCOURSEPROJECTKNU_TRIANGLE2D_H
#define CPPCOURSEPROJECTKNU_TRIANGLE2D_H

#include <ostream>
#include "../FigureComponents/Point.h"
#include "../FigureComponents/Figure.h"

struct TriangleEdgesLength{
private:
    double AB;
    double BC;
    double AC;
public:
    TriangleEdgesLength(double ab, double bc, double ac);

    double getAb() const;
    double getBc() const;
    double getAc() const;

    friend std::ostream &operator<<(std::ostream &os, const TriangleEdgesLength &length);
};

class Triangle2D : public  Figure{
private:
    Point* points;

public:
    Triangle2D(const Point &a, const Point &b, const Point &c);
    virtual ~Triangle2D();

    bool isConvex() override;
    double perimeter() override;

    TriangleEdgesLength getEdgesLength();
    double area();

    friend std::ostream &operator<<(std::ostream &os, const Triangle2D &triangle);
};


#endif //CPPCOURSEPROJECTKNU_TRIANGLE2D_H
