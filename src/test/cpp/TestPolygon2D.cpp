#include "iostream"
#include "Test.cpp"
#include "../../main/cpp/Figures/Polygon2D.h"

class TestPolygon2D {
private:
    Test test;
    std::ostream &log;
    std::ostream &err;
public:
    TestPolygon2D(std::ostream &log, std::ostream &err) : log(log), err(err),
            test("TestPolygon2D", log, err) {
    }

    void run(){
        testIsConvex();
        testTriangulation();
    }

    void testIsConvex(){
        TestCase _ = test.test("testIsConvex");

        Point2D points1[6] = {
                Point2D(2,1),
                Point2D(7,2),
                Point2D(8,5),
                Point2D(5,7),
                Point2D(2,5),
                Point2D(4,4)
        };

        Point2D points2[5] = {
                Point2D(2,1),
                Point2D(7,2),
                Point2D(8,5),
                Point2D(5,7),
                Point2D(2,5)
        };

        Polygon2D polygon1(points1,6);
        Polygon2D polygon2(points2,5);

        _.assertFalse(polygon1.isConvex());
        _.assertTrue(polygon2.isConvex());
    }

    void testTriangulation(){
        TestCase _ = test.test("testTriangulation");
        Point2D points1[6] = {
                Point2D(2,1),
                Point2D(7,2),
                Point2D(8,5),
                Point2D(5,7),
                Point2D(2,5),
                Point2D(4,4)
        };

        Polygon2D polygon1(points1,6);

        std::set<Triangle2D> triangles;

        triangles.insert(Triangle2D(points1[0],points1[1],points1[5]));
        triangles.insert(Triangle2D(points1[1],points1[2],points1[5]));
        triangles.insert(Triangle2D(points1[2],points1[5],points1[3]));
        triangles.insert(Triangle2D(points1[3],points1[5],points1[4]));



        std::vector<Triangle2D> t = polygon1.triangulation();
        std::set<Triangle2D> triangulation(t.begin(),t.end());

        _.assertTrue(triangles==triangulation);
    }

};

