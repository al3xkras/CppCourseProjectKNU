#include "Line2D.h"
#include "iostream"

Point2D& Line2D::intersection(AbstractLine* other) {
    Point2D* point2D = nullptr;
    auto *segment2D = dynamic_cast<Segment2D*>(other);
    if (segment2D){
        (*point2D) = (*segment2D).intersection(this);
    }
    delete segment2D;
    auto *line2D = dynamic_cast<Line2D*>(other);
    if (line2D){

        double h1 = (*this).getH();
        double x1 = (*this).getLineVector().getX();
        double y1 = (*this).getLineVector().getY();

        double h2 = (*line2D).getH();
        double x2 = (*line2D).getLineVector().getX();
        double y2 = (*line2D).getLineVector().getY();

        if ((long)((y1-h1)*1000)==0 ||
            (long)((y2-h2)*1000)==0 ||
            (long)((x1*(y2-h2)-x2*(y1-h1))*1000)==0){
            return *point2D;
        }

        double y = (x1*h1*(y2-h2)-x2*h2*(y1-h1))
                    /
                   (x1*(y2-h2)-x2*(y1-h1));

        double x = x1 * (y-h1) / (y1-h1);
        (*point2D) = Point2D(x,y);

        return *point2D;
    }
    std::cout<<"Bad cast (Line2D.cpp, line 37)";
    throw std::bad_cast();
}
