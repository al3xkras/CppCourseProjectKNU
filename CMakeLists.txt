cmake_minimum_required(VERSION 3.20)
project(CppCourseProjectKNU)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppCourseProjectKNU main.cpp src/main/cpp/FigureComponents/Point2D.cpp src/main/cpp/FigureComponents/Point2D.h src/main/cpp/Figures/abstract/Figure.h)
