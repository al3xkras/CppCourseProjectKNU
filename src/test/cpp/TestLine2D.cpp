#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/FigureComponents/Line2D.h"

class TestLine2D{
private:
    Test test;
    std::ostream &log;
    std::ostream &err;
public:

    TestLine2D(std::ostream &log, std::ostream &err) : log(log), err(err), test("TestLine2D", log, err){

    }

    void run(){
        testLineIntersection();
        testLineAndSegmentIntersection();
        testEquals();
    }

    void testLineIntersection(){
        TestCase _ = test.test("testLineIntersection");

        Line2D line1(0,1,1);
        Line2D line2(1,1,1);
        Line2D line3(1,1,-1);
        Line2D line4(1,1,1);

        Point2D p1 = line1.intersection(line2);
        _.name("no intersection").assertEquals(Point2D(DBL_MIN,DBL_MIN),p1);

        Point2D p2 = line1.intersection(line3);
        _.assertEquals(Point2D(0.5,0.5),p2);

        Point2D p3 = line2.intersection(line4);
        _.name("intersection 2").assertEquals(Point2D(0,1),p3);

    }

    void testLineAndSegmentIntersection(){
        double eps = 0.1;
        TestCase _ = test.test("testLineAndSegmentIntersection");

        Line2D line1(-1,2,1);
        Segment2D segment1(Point2D(1,-1),Point2D(5,-2));
        Segment2D segment2(Point2D(-2,0),Point2D(4,0));
        Segment2D segment3(Point2D(6,-2),Point2D(6,3));
        Segment2D segment4(Point2D(2,2),Point2D(6,0));

        Point2D p1 = line1.intersection(segment1);
        Point2D p2 = line1.intersection(segment2);
        Point2D p3 = line1.intersection(segment3);
        Point2D p4 = line1.intersection(segment4);

        _.name("no intersection").assertEquals(p1,Point2D(DBL_MIN,DBL_MIN));

        _.name("has intersection 1").assertTrue(Point2D(2,0).distanceTo(p2)<eps);
        _.name("has intersection 2").assertTrue(Point2D(6,2).distanceTo(p3)<eps);
        _.name("has intersection 3").assertTrue(Point2D(4,1).distanceTo(p4)<eps);
    }


    void testEquals(){
        TestCase _ = test.test("testEquals");

        Line2D line1(0,1,1);
        Line2D line2(0,1,1.00001);
        Line2D line3(1,1,1);
        Line2D line4(0,1,1);

        _.name("equals 1").assertEquals(line1,line4);
        _.name("equals 2").assertNotEquals(line1,line2);
        _.name("equals 3").assertNotEquals(line1,line3);
        _.name("equals 4").assertEquals(line1,line1);
    }


};