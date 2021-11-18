#ifndef CPPCOURSEPROJECTKNU_FIGURE_H
#define CPPCOURSEPROJECTKNU_FIGURE_H

class Figure {
public:
    virtual void isConvex() = 0;
    virtual double perimeter() = 0;

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure) {
        return os;
    };
};

#endif //CPPCOURSEPROJECTKNU_FIGURE_H
