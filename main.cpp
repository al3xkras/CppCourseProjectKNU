#include <iostream>

#include "src/main/cpp/FigureComponents/Line2D.h"
#include "src/main/cpp/Figures/Triangle2D.h"
#include "src/main/cpp/Figures/Polygon2D.h"
#include "src/main/cpp/FigureComponents/Polyline2D.h"
#include "src/test/cpp/Test.cpp"
#include "src/test/cpp/TestLine.cpp"

void testFigureComponents(){
    Point2D point1(0,0);
    Point2D point2(1,1);
    Point2D point3(1,0);
    Point2D point4(2,0);

    Segment2D segment1(point1,point2);
    Segment2D segment2(point3,point4);
    Line2D line1(1.0, -1.0, 1.0);
    Line2D line2(1.0,2,-2);
    //std::cout<<segment2D<<std::endl;
    Point2D p1 = segment1.intersection(line1);
    Point2D p2 = segment1.intersection(segment2);
    Point2D p3 = line1.intersection(line2);

    std::cout<<"p1 "<<p1<<std::endl;
    std::cout<<"p2 "<<p2<<std::endl;
    std::cout<<"p3 "<<p3<<std::endl;

}

void testFigures(){
    Triangle2D triangle2D(Point2D(0,0),Point2D(0,1),Point2D(1,0));

    Point2D points[6] = {
            Point2D(2,1),
            Point2D(7,2),
            Point2D(8,5),
            Point2D(5,7),
            Point2D(2,5),
            Point2D(4,4)
    };
    Polygon2D polygon2D(points,6);

    std::cout << *dynamic_cast<Figure*>(&triangle2D) << std::endl;
    std::cout << *dynamic_cast<Figure*>(&polygon2D) << std::endl;

    std::cout << std::boolalpha << "Is convex: " << polygon2D.isConvex() << std::endl;
}

void testPolyline(){
    Point2D points[7] = {
            Point2D(2,1),
            Point2D(7,2),
            Point2D(8,5),
            Point2D(5,7),
            Point2D(2,5),
            Point2D(4,4),
            Point2D(4,8)
    };

    Segment2D s1(Point2D(5,7),Point2D(2,5));
    Segment2D s2(Point2D(4,4),Point2D(4,8));

    Polyline2D pLine(points,7);
    //std::cout << pLine <<" Has self-intersections: "<<std::boolalpha<<pLine.hasSelfIntersections()<< std::endl;
    std::cout<<std::boolalpha<<pLine.hasSelfIntersections()<< std::endl;

    //std::cout<<*s1.intersection(&s2)<<std::endl;
}

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
    TestLine testLine(std::cout, std::cerr);
    testLine.run();
}

int main() {
    runTests();

    return 0;
}
