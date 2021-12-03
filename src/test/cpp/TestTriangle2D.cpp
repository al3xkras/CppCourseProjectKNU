#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/Figures/Triangle2D.h"

class TestTriangle2D {
private:
    Test test;
    std::ostream &log;
    std::ostream &err;
public:
    TestTriangle2D(std::ostream &log, std::ostream &err) : log(log), err(err),
            test("TestTriangle2D", log, err) {
    }

    void run(){
        testIsConvex();
        testPerimeter();
    }

    void testIsConvex(){
        TestCase _ = test.test("testIsConvex");

        Triangle2D t1(Point2D(0,0),Point2D(0,1),Point2D(1,0));
        Triangle2D t2(Point2D(0,0),Point2D(0,1),Point2D(0,1));

        _.assertTrue(t1.isConvex());
        _.assertFalse(t2.isConvex());
    }

    void testPerimeter(){
        TestCase _ = test.test("testPerimeter");

        Triangle2D t1(Point2D(0,0),Point2D(0,4),Point2D(3,0));

        _.assertEquals(t1.perimeter(),(double)(3+4+5));
    }
};
