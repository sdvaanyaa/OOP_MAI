#pragma once

#include "shape.h"
#include "point.h"
#include <string>

class Trapezoid: public Shape 
{
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& t);
    friend std::istream& operator>>(std::istream& is, Trapezoid& t);
public:
    Trapezoid() = default;
    Trapezoid(Point _a, Point _b, Point _с, Point _d);

    explicit operator double() const;

    void operator=(const Trapezoid& right_operand);
    void operator=(Trapezoid&& right_operand);
    bool operator==(const Trapezoid& rpoint) const;
    
    virtual double surface() const override;
    virtual Point center() const override;

    virtual void printCout() const;
    virtual void readCin();
    
    Point getA();
    Point getB();
    Point getC();
    Point getD();

    virtual ~Trapezoid() = default;

private: 
    Point _a{0.0, 0.0};
    Point _b{0.0, 0.0};
    Point _c{0.0, 0.0};
    Point _d{0.0, 0.0};
};
