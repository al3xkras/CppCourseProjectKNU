#include "Line2D.h"
#include "iostream"

Point2D Line2D::intersection(AbstractLine &other) {
    auto *segment2D = dynamic_cast<Segment2D*>(&other);
    if (segment2D){
        return (*segment2D).intersection(*this);
    }
    auto* line2D = dynamic_cast<Line2D*>(&other);

    if (line2D){
        double x11 = 0;
        double y11 = (*this).getH();
        double v11 = (*this).getLineVector().getX();
        double v21 = (*this).getLineVector().getY();

        double x12 = 0;
        double y12 = (*line2D).getH();
        double v12 = (*line2D).getLineVector().getX();
        double v22 = (*line2D).getLineVector().getY();

        if (y12==y11 && (long)((v11/v12)*1000L) == (long)((v21/v22)*1000L)){
            return {0,y11};
        }

        if ((long)((v21*v12-v22*v11)*1000)==0){
            return {DBL_MIN,DBL_MIN};
        }

        double _1 = v11*v12/(v21*v12-v22*v11);
        double _2 = y12-y11 + v21*x11/v11 - v22*x12/v12;

        double x = _1*_2;
        double y = y11 + v21/v11*(x-x11);

        return {x,y};
    }
    std::cout<<"Bad cast (Line2D.cpp, line 37)";
    throw std::bad_cast();
}

double Line2D::operator()(const double x1) {
    return h_Y + line_vector.getY() / line_vector.getX() * x1 ;
}

std::ostream &operator<<(std::ostream &os, const Line2D &d) {
    os << " h_Y: " << d.h_Y << " line_vector: " << d.line_vector;
    return os;
}
