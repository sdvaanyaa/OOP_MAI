#pragma once

#include "point.h"
#include <string>

class Shape
{
public:
    Shape() = default;
    
    virtual explicit operator double() const = 0;
    virtual double surface() const = 0;
    virtual Point center() const = 0;

    virtual void printCout() const {
       std::cout << "Shape: " << "[ a : " << _a << ", b : " << _b << ", c : " << _c << ", d : " << _d << "]";
    };
    virtual void readCin() {
        std::cout << "Enter 4 points for shape: " << std::endl;
        std::cout.flush();
        std::cin >> _a >> _b >> _c >> _d;
    };

    virtual ~Shape() = default;
private:
    Point _a {0.0, 0.0};
    Point _b {0.0, 0.0};
    Point _c {0.0, 0.0};
    Point _d {0.0, 0.0};
};

