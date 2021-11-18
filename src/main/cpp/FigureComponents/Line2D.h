#ifndef CPPCOURSEPROJECTKNU_LINE2D_H
#define CPPCOURSEPROJECTKNU_LINE2D_H

#include "Vector2D.h"
#include "Point2D.h"
#include "Segment2D.h"
#include "abstract/AbstractLine.h"

class Line2D: public AbstractLine {
private:
    double h_x2;
    Vector2D* line_vector;
public:
    Line2D(double h_x2, double vec_x1, double vec_x2){
        this->h_x2=h_x2;
        Vector2D vector2D = Vector2D(vec_x1,vec_x2);
        line_vector = &vector2D;
    }

    Point2D& intersection(AbstractLine* other) override;

    bool operator==(const Line2D &other) const {
        return h_x2 == other.h_x2 && line_vector == other.line_vector;
    }
    bool operator!=(const Line2D &other) const {
        return !(other == *this);
    }
    double getH() const {
        return h_x2;
    }
    Vector2D getLineVector() const {
        return *line_vector;
    }
};


#endif //CPPCOURSEPROJECTKNU_LINE2D_H
