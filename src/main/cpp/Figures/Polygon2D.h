#ifndef CPPCOURSEPROJECTKNU_POLYGON2D_H
#define CPPCOURSEPROJECTKNU_POLYGON2D_H


#include <ostream>
#include "../Figures/abstract/Figure.h"
#include "../FigureComponents/Point2D.h"

class Polygon2D : public Figure{
private:
    size_t points_size;
    Point2D* points;
public:
    Polygon2D(Point2D* points, size_t points_size);
    virtual ~Polygon2D();

    bool isConvex() override;
    double perimeter() override;
    void toString(std::ostream &os) override;
};


#endif //CPPCOURSEPROJECTKNU_POLYGON2D_H
