#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/FigureComponents/Polyline2D.h"

class TestPolyline2D {
private:
    Test test;
    std::ostream &log;
    std::ostream &err;
public:

    TestPolyline2D(std::ostream &log, std::ostream &err) : log(log), err(err),
            test("TestPolyline2D", log, err) {
    }

    void run(){
        testHasSelfIntersections();
    }

    void testHasSelfIntersections(){
        TestCase _ = test.test("testHasSelfIntersections");

        Point2D points[7] = {
                Point2D(2,1),
                Point2D(7,2),
                Point2D(8,5),
                Point2D(5,7),
                Point2D(2,5),
                Point2D(4,4),
                Point2D(4,8)
        };

        Point2D points2[6] = {
                Point2D(2,1),
                Point2D(7,2),
                Point2D(8,5),
                Point2D(5,7),
                Point2D(2,5),
                Point2D(4,4)
        };

        Segment2D s1(Point2D(5,7),Point2D(2,5));
        Segment2D s2(Point2D(4,4),Point2D(4,8));

        Polyline2D pLine(points,7);
        Polyline2D pLine2(points2,6);

        _.assertTrue(pLine.hasSelfIntersections());
        _.assertFalse(pLine2.hasSelfIntersections());
    }

};

