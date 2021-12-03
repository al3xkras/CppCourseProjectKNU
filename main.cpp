#include <iostream>

#include "src/main/cpp/FigureComponents/Line2D.h"
#include "src/main/cpp/Figures/Triangle2D.h"
#include "src/main/cpp/Figures/Polygon2D.h"
#include "src/test/cpp/TestLine2D.cpp"
#include "src/test/cpp/TestSegment2D.cpp"
#include "src/test/cpp/TestPolyline2D.cpp"
#include "src/test/cpp/TestPolygon2D.cpp"
#include "src/test/cpp/TestTriangle2D.cpp"

void testTriangulation(){
    Point2D points[6] = {
            Point2D(2,1),
            Point2D(7,2),
            Point2D(8,5),
            Point2D(5,7),
            Point2D(2,5),
            Point2D(4,4)
    };
    Polygon2D polygon2D(points,6);

    std::vector<Triangle2D> triangulation = polygon2D.triangulation();

    for (Triangle2D triangle2D: triangulation){
        std::cout<<triangle2D<<std::endl;
    }
}

void testArea(){
    Point2D points[6] = {
            Point2D(2,1),
            Point2D(7,2),
            Point2D(8,5),
            Point2D(5,7),
            Point2D(2,5),
            Point2D(4,4)
    };
    Polygon2D polygon2D(points,6);



    double real = 0;
    std::vector<Triangle2D> triangulation = polygon2D.triangulation();
    for (Triangle2D triangle2D: triangulation){
        std::cout<<triangle2D.area()<<std::endl;
        real+=triangle2D.area();
    }

    std::cout<<"actual: "<<polygon2D.area()<<" expected: "<<real<<std::endl;
}

void runTests(){
    TestLine2D testLine(std::cout, std::cerr);
    TestPolygon2D testPolygon2D(std::cout, std::cerr);
    TestPolyline2D testPolyline(std::cout, std::cerr);
    TestTriangle2D testTriangle2D(std::cout, std::cerr);
    TestSegment2D testSegment(std::cout, std::cerr);

    testLine.run();
    testPolygon2D.run();
    testPolyline.run();
    testTriangle2D.run();
    testSegment.run();
}

int main() {
    runTests();
    return 0;
}
