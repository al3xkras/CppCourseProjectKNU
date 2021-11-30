#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/FigureComponents/Line2D.h"

class TestLine{
private:
    Test t;
    std::ostream &log;
    std::ostream &err;
public:

    TestLine(std::ostream &log, std::ostream &err) : log(log), err(err), t("TestLine", log, err){

    }

    void run(){
        testLineIntersection();
    }

    void testLineIntersection(){
        TestCase _ = t.test("testLineIntersection");

        Line2D line1(0,1,1);
        Line2D line2(1,1,1);
        Line2D line3(1,1,-1);
        Line2D line4(1,1,1);

        Point2D p1 = line1.intersection(line2);

        Point2D p2 = line1.intersection(line3);

        _.name("intersection 1").assertEquals(Point2D(0.5,0.5),p2);



        Point2D p3 = line2.intersection(line4);

        _.name("intersection 2").assertEquals(Point2D(0,1),p3);

    }


};