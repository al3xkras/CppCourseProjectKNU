#ifndef CPPCOURSEPROJECTKNU_TRIANGLE2D_H
#define CPPCOURSEPROJECTKNU_TRIANGLE2D_H

#include <ostream>
#include <vector>
#include <set>
#include "../FigureComponents/Point2D.h"
#include "../Figures/abstract/Figure.h"

struct TriangleEdgesLength{
private:
    double AB;
    double BC;
    double AC;
public:
    TriangleEdgesLength(double ab, double bc, double ac);

    double getAb() const;
    double getBc() const;
    double getAc() const;

    friend std::ostream &operator<<(std::ostream &os, const TriangleEdgesLength &length);
};

class Triangle2D : public  Figure{
private:
    std::vector<Point2D> points;

public:
    Triangle2D(const Point2D &a, const Point2D &b, const Point2D &c);
    virtual ~Triangle2D();

    bool isConvex() override;

    double p() const;

    double perimeter() override{
        return p();
    }

    TriangleEdgesLength getEdgesLength() const;
    double area();

    std::ostream &toString(std::ostream &os) override;

    bool operator==(const Triangle2D &rhs) const{
        std::set<Point2D> p1(points.begin(),points.end());
        std::set<Point2D> p2(rhs.points.begin(),rhs.points.end());
        return p1==p2;
    }

    bool operator!=(const Triangle2D &rhs) const{
        return !(*this==rhs);
    }

    bool operator<(const Triangle2D &rhs) const{
        return (p()<rhs.p());
    }

    bool operator>(const Triangle2D &rhs) const;

    bool operator<=(const Triangle2D &rhs) const;

    bool operator>=(const Triangle2D &rhs) const;
};


#endif //CPPCOURSEPROJECTKNU_TRIANGLE2D_H
