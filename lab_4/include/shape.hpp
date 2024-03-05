#pragma once
#include "point.hpp"
#include <string>

#define POINT_COUNT 4

template <Number T>
class Shape
{
public:
    Shape() = default;

    virtual explicit operator double() const = 0;
    virtual double surface() const = 0;
    virtual Point<T> center() const = 0;

    virtual void printCout() const
    {
        std::cout << "Shape: "
                  << "[ a : " << _a << ", b : " << _b << ", c : " << _c << ", d : " << _d << "]";
    };
    virtual void readCin()
    {
        std::cout << "Enter 4 points for shape: " << std::endl;
        std::cin >> _a >> _b >> _c >> _d;
    };

    virtual ~Shape() = default;

private:
    Point<T> _a{0, 0};
    Point<T> _b{0, 0};
    Point<T> _c{0, 0};
    Point<T> _d{0, 0};
};