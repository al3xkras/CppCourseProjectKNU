#ifndef CPPCOURSEPROJECTKNU_VECTOR2D_H
#define CPPCOURSEPROJECTKNU_VECTOR2D_H


class Vector2D {
private:
    double x1;
    double x2;
public:
    Vector2D(double x1, double x2);

    bool operator==(const Vector2D &rhs) const;
    bool operator!=(const Vector2D &rhs) const;
    Vector2D &operator+(const Vector2D &other) const;
    double operator*(const Vector2D &other) const;

    double getX() const;
    double getY() const;
};


#endif //CPPCOURSEPROJECTKNU_VECTOR2D_H
