#pragma once

#include "shape.h"
#include "point.h"

class Rectangle: public Shape 
{
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r);
    friend std::istream& operator>>(std::istream& is, Rectangle& r);
public:
    Rectangle() = default;
    Rectangle(Point _a, Point _b, Point _с, Point _d);

    void operator=(const Rectangle& right_operand);
    void operator=(Rectangle&& right_operand);
    bool operator==(const Rectangle& rpoint) const;

    explicit operator double() const; //return surface

    virtual double surface() const override;
    virtual Point center() const override;

    virtual void printCout() const;
    virtual void readCin();

    Point getA();
    Point getB();
    Point getC();
    Point getD();

    virtual ~Rectangle() = default;
private: 
    Point _a{0.0, 0.0};
    Point _b{0.0, 0.0};
    Point _c{0.0, 0.0};
    Point _d{0.0, 0.0};
};
