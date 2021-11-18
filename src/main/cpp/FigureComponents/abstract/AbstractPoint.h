#ifndef CPPCOURSEPROJECTKNU_ABSTRACTPOINT_H
#define CPPCOURSEPROJECTKNU_ABSTRACTPOINT_H

const double DBL_MIN = -3e307;

class AbstractPoint {
public:
    virtual double getCoordinate(int index) = 0;
};


#endif //CPPCOURSEPROJECTKNU_ABSTRACTPOINT_H
