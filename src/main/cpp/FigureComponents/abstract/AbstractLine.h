#ifndef CPPCOURSEPROJECTKNU_ABSTRACTLINE_H
#define CPPCOURSEPROJECTKNU_ABSTRACTLINE_H


#include "../Point2D.h"
#include "AbstractPoint.h"

class AbstractLine {
    virtual AbstractPoint& intersection(AbstractLine* other) = 0;
};


#endif //CPPCOURSEPROJECTKNU_ABSTRACTLINE_H
