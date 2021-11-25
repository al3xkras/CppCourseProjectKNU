cmake_minimum_required(VERSION 3.20)
project(CppCourseProjectKNU)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppCourseProjectKNU main.cpp
        src/main/cpp/FigureComponents/Point2D.cpp
        src/main/cpp/FigureComponents/Point2D.h
        src/main/cpp/Figures/abstract/Figure.h
        src/main/cpp/FigureComponents/Line2D.cpp
        src/main/cpp/FigureComponents/Line2D.h
        src/main/cpp/FigureComponents/Vector2D.cpp
        src/main/cpp/FigureComponents/Vector2D.h
        src/main/cpp/FigureComponents/Polyline2D.cpp
        src/main/cpp/FigureComponents/Polyline2D.h
        src/main/cpp/FigureComponents/abstract/AbstractLine.h
        src/main/cpp/FigureComponents/abstract/AbstractPoint.h
        src/main/cpp/FigureComponents/Segment2D.h
        src/main/cpp/FigureComponents/Segment2D.cpp
        src/main/cpp/Figures/Triangle2D.h
        src/main/cpp/Figures/Triangle2D.cpp)
