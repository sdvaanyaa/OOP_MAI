#pragma once

#include "shape.h"
#include "point.h"

class Square: public Shape 
{
    friend std::ostream& operator<<(std::ostream& os, const Square& s);
    friend std::istream& operator>>(std::istream& is, Square& s);
public:
    Square() = default;
    Square(Point _a, Point _b, Point _с, Point _d);
    void operator=(const Square& right_operand);
    void operator=(Square&& right_operand);
    bool operator==(const Square& rpoint) const;
    explicit operator double() const;
    
    virtual double surface() const override;
    virtual Point center() const override;

    virtual void printCout() const;
    virtual void readCin();

    Point getA();
    Point getB();
    Point getC();
    Point getD();

    virtual ~Square() = default; 

private: 
    Point _a{0.0, 0.0};
    Point _b{0.0, 0.0};
    Point _c{0.0, 0.0};
    Point _d{0.0, 0.0};
};

