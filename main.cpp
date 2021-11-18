#include <iostream>

#include "src/main/cpp/FigureComponents/Line2D.h"
#include "src/main/cpp/FigureComponents/Segment2D.h"

int main() {

    Point2D point1(0,0);
    Point2D point2(1,1);

    Segment2D segment2D(point1,point2);

    std::cout<<segment2D<<std::endl;

    return 0;
}
