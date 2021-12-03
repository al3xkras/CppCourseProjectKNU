#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/FigureComponents/Segment2D.h"

class TestSegment2D {
private:
    Test test;
    std::ostream &log;
    std::ostream &err;
public:

    TestSegment2D(std::ostream &log, std::ostream &err) : log(log), err(err),
        test("TestSegment2D", log, err) {
    }

    void run(){
        testSegmentAndLineIntersection();
        testSegmentContainsPoint();
        testEquals();
    }

    void testSegmentAndLineIntersection(){
        const double eps = 0.1;

        TestCase _ = test.test("testSegmentAndLineIntersection");

        Line2D line1(-1,2,1);
        Segment2D segment1(Point2D(1,-1),Point2D(5,-2));
        Segment2D segment2(Point2D(-2,0),Point2D(4,0));
        Segment2D segment3(Point2D(6,-2),Point2D(6,3));
        Segment2D segment4(Point2D(2,2),Point2D(6,0));

        Point2D p1 = segment1.intersection(line1);
        Point2D p2 = segment2.intersection(line1);
        Point2D p3 = segment3.intersection(line1);
        Point2D p4 = segment4.intersection(line1);

        _.name("no intersection").assertEquals(p1,Point2D(DBL_MIN,DBL_MIN));
        _.name("intersection 1").assertTrue(Point2D(2,0).distanceTo(p2)<eps);
        _.name("intersection 2").assertTrue(Point2D(6,2).distanceTo(p3)<eps);
        _.name("intersection 3").assertTrue(Point2D(4,1).distanceTo(p4)<eps);
    }

    void testSegmentContainsPoint(){
        TestCase _ = test.test("testSegmentContainsPoint");

        Segment2D segment1(Point2D(-6,-1),Point2D(9,9));
        Point2D p1(6,7);
        Point2D p2(-3,1);
        Point2D p3(1,-3);

        segment1.containsPoint(p1);

        _.assertTrue(segment1.containsPoint(p1));
        _.assertTrue(segment1.containsPoint(p2));
        _.assertFalse(segment1.containsPoint(p3));
    }

    void testEquals(){
        TestCase _ = test.test("testEquals");
        Segment2D segment1(Point2D(1,-1),Point2D(5,-2));
        Segment2D segment2(Point2D(-2,0),Point2D(4,0));
        Segment2D segment3(Point2D(1,-1),Point2D(5,-2));
        Segment2D segment4(Point2D(1,-1),Point2D(5,-2.000004));
        _.name("equals 1").assertEquals(segment1,segment3);
        _.name("equals 2").assertNotEquals(segment1,segment2);
        _.name("equals 3").assertNotEquals(segment1,segment4);
        _.name("equals 4").assertEquals(segment1,segment1);
    }

};
