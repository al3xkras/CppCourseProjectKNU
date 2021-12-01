#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/FigureComponents/Segment2D.h"

class TestSegment2D {
private:
    Test t;
    std::ostream &log;
    std::ostream &err;
public:

    TestSegment2D(std::ostream &log, std::ostream &err) : log(log), err(err),
        t("TestSegment2D", log, err) {
    }

    void run(){
        testSegmentIntersection();
        testSegmentAndLineIntersection();
    }

    void testSegmentIntersection(){

    }

    void testSegmentAndLineIntersection(){

    }

    void testSegmentContainsPoint(){
        TestCase _ = t.test("testSegmentContainsPoint");

        Segment2D segment1(Point2D(-6,-1),Point2D(9,9));
        Point2D p1(6,7);
        Point2D p2(-3,1);
        Point2D p3(1,3);

        segment1.containsPoint(p1);
        _.assertTrue(segment1.containsPoint(p1));
        _.assertTrue(segment1.containsPoint(p2));
        _.assertFalse(segment1.containsPoint(p3));

    }

};
