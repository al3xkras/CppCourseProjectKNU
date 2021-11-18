#include "Polygon2D.h"
#include "../FigureComponents/Line2D.h"
#include "cmath"

Polygon2D::Polygon2D(Point *points, size_t points_size) {
    this->points = points;
    this->points_size=points_size;
}

bool Polygon2D::isConvex() {
    for (int i=0; i<points_size; i++){
        int j = (i+1)%points_size;
        Line2D currentEdge(points[i],points[j]);

        //std::cout<<i<<std::endl<<j<<std::endl<<currentEdge<<std::endl;
        int previous_sign = 0;
        for (int k=0; k<points_size; k++){
            if (k==i || k==j)
                continue;
            Point p_k = points[k];
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
    delete[](points);
}

std::ostream &operator<<(std::ostream &os, const Polygon2D &polygon) {
    os<<"Polygon2D: ";
    for (int i=0; i<polygon.points_size; i++){
        os<<'('<<polygon.points[i]<<") ";
    }
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