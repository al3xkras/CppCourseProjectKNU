#ifndef CPPCOURSEPROJECTKNU_LINE2D_H
#define CPPCOURSEPROJECTKNU_LINE2D_H

#include "Vector2D.h"
#include "Point2D.h"
#include "Segment2D.h"
#include "abstract/AbstractLine.h"

class Line2D: public AbstractLine {
private:
    double h_Y;
    Vector2D line_vector;
public:
    Line2D(double h_x2, double vec_x1, double vec_x2): line_vector(vec_x1,vec_x2){
        this->h_Y=h_x2;
    }

    Point2D* intersection(AbstractLine* other) override;

    bool operator==(const Line2D &other) const {
        return h_Y == other.h_Y && line_vector == other.line_vector;
    }
    bool operator!=(const Line2D &other) const {
        return !(other == *this);
    }
    double operator()(const double x1);

    double getH() {
        return h_Y;
    }
    Vector2D getLineVector() {
        return line_vector;
    }
};


#endif //CPPCOURSEPROJECTKNU_LINE2D_H
