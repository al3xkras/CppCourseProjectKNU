#include <iostream>

#include "src/main/cpp/FigureComponents/Line2D.h"

int main() {

    Point2D point1(0,0);
    Point2D point2(1,1);
    Point2D point3(1,0);
    Point2D point4(2,0);

    Segment2D segment1(point1,point2);
    Segment2D segment2(point3,point4);
    Line2D line1(1.0, -1.0, 1.0);
    Line2D line2(1.0,2,-2);
    //std::cout<<segment2D<<std::endl;
    Point2D* p1 = segment1.intersection(&line1);
    Point2D* p2 = segment1.intersection(&segment2);
    Point2D* p3 = line1.intersection(&line2);

    std::cout<<"p1 "<<*p1<<std::endl;
    std::cout<<"p2 "<<*p2<<std::endl;
    std::cout<<"p3 "<<*p3<<std::endl;

    free(p1);
    free(p2);
    free(p3);

    return 0;
}
