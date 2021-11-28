#ifndef CPPCOURSEPROJECTKNU_POLYGON2D_H
#define CPPCOURSEPROJECTKNU_POLYGON2D_H


#include <ostream>
#include <vector>
#include "../Figures/abstract/Figure.h"
#include "../FigureComponents/Point2D.h"
#include "Triangle2D.h"

class Polygon2D : public Figure{
private:
    size_t points_size;
    std::vector<Point2D> points;
public:
    Polygon2D(Point2D* points, size_t points_size);
    virtual ~Polygon2D();

    std::vector<Triangle2D> triangulation();

    bool isConvex() override;
    double perimeter() override;
    double area();
    std::ostream &toString(std::ostream &os) override;
};


#endif //CPPCOURSEPROJECTKNU_POLYGON2D_H
