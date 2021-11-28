#include <iostream>
#include "Polygon2D.h"
#include "../FigureComponents/Segment2D.h"
#include "cmath"

#include "../triangulate/triangulate.h"

Polygon2D::Polygon2D(Point2D *points, size_t points_size): points(points_size) {
    for (int i=0; i<points_size; i++){
        this->points[i] = points[i];
    }
    this->points_size=points_size;
}

bool Polygon2D::isConvex() {
    for (int i=0; i<points_size; i++){
        int j = (i+1)%points_size;
        Segment2D currentEdge(points[i], points[j]);

        //std::cout<<i<<std::endl<<j<<std::endl<<currentEdge<<std::endl;
        int previous_sign = 0;
        for (int k=0; k<points_size; k++){
            if (k==i || k==j)
                continue;
            Point2D p_k = points[k];
            if (previous_sign==0){
                previous_sign=std::signbit(currentEdge.angleWithPoint(p_k))?-1:1;
                continue;
            }

            double angle = currentEdge.angleWithPoint(p_k);
            int sign = std::signbit(angle)?-1:1;
            //std::cout<<angle<<' '<<sign<<std::endl;

            if (sign!=previous_sign) {
                //std::cout << currentEdge << std::endl << p_k << std::endl;
                return false;
            }
            previous_sign=sign;
        }
    }
    return true;
}

Polygon2D::~Polygon2D() {
}

std::ostream &operator<<(std::ostream &os, const Polygon2D &polygon) {

    return os;
}

double Polygon2D::perimeter() {
    double perimeter = 0;
    for (int i=0; i<points_size; i++) {
        int j = (i + 1) % points_size;
        perimeter += points[i].distanceTo(points[j]);
    }
    return perimeter;
}

std::ostream &Polygon2D::toString(std::ostream &os) {
    os<<"Polygon2D: ";
    for (int i=0; i<points_size; i++){
        os<<'('<<points[i]<<") ";
    }
    return os;
}

std::vector<Triangle2D> Polygon2D::triangulation() {
    double x[points_size];
    double y[points_size];

    for (int i=0; i<points_size; i++){
        x[i] = points[i].getX();
        y[i] = points[i].getY();
    }

    int* triangulation = polygon_triangulate((int)points_size,x,y);

    std::vector<Triangle2D> triangles;

    for (int i=0; i<3*(points_size-2); i+=3){
        Point2D a(points[triangulation[i]]);
        Point2D b(points[triangulation[i+1]]);
        Point2D c(points[triangulation[i+2]]);

        triangles.emplace_back(a,b,c);
    }

    delete triangulation;

    return triangles;
}
