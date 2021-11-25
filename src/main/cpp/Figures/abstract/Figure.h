#ifndef CPPCOURSEPROJECTKNU_FIGURE_H
#define CPPCOURSEPROJECTKNU_FIGURE_H

class Figure {
public:
    virtual bool isConvex() = 0;
    virtual double perimeter() = 0;

    virtual std::ostream &toString(std::ostream &os) {
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, Figure &figure) {
        return figure.toString(os);
    };
};

#endif //CPPCOURSEPROJECTKNU_FIGURE_H
