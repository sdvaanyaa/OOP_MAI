#pragma once

#include <iostream>
#include <math.h>

class Point
{
    friend std::ostream& operator << (std::ostream& out , const Point& point);
    friend std::istream& operator >> (std::istream& in, Point& point);
public:
    Point() = default;
    Point(double x ,double y);
    ~Point() = default;

    Point& operator=(const Point& right_operand);
    bool operator==(const Point& rpoint) const;
    bool operator<(const Point& rpoint) const;
    bool operator>(const Point& rpoint) const;

    double distanceTo(const Point& rpoint) const;
   
public: 
    double m_x{0.0};
    double m_y{0.0};
};

