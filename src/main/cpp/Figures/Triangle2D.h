#ifndef CPPCOURSEPROJECTKNU_TRIANGLE2D_H
#define CPPCOURSEPROJECTKNU_TRIANGLE2D_H

#include <ostream>
#include "../FigureComponents/Point2D.h"
#include "../Figures/abstract/Figure.h"

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
    Point2D* points;

public:
    Triangle2D(const Point2D &a, const Point2D &b, const Point2D &c);
    virtual ~Triangle2D();

    bool isConvex() override;
    double perimeter() override;

    TriangleEdgesLength getEdgesLength();
    double area();

    std::ostream &toString(std::ostream &os) override;
};


#endif //CPPCOURSEPROJECTKNU_TRIANGLE2D_H
