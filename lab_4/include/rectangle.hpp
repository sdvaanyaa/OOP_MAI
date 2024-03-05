#pragma once
#include "shape.hpp"
#include "point.hpp"

template <Number T>
class Rectangle: public Shape<T>
{
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<T>& r)
    {
        os << "[ a : " << r._a << ", b : " << r._b << ", c : " << r._c << ", d : " << r._d << "]";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Rectangle<T>& r)
    {
        Point<T> a, b, c, d;
        is >> a >> b >> c >> d;
        r = Rectangle(a, b, c, d);
        return is;
    }
public:
    Rectangle() = default;
    Rectangle(Rectangle<T>* s)
    {
        *this = *s;
    }
    Rectangle(Point<T> a, Point<T> b, Point<T> c, Point<T> d)
    {
        Point<T> points[POINT_COUNT] = {a, b, c, d};
        std::sort(points, points + POINT_COUNT);
        a = points[0];
        b = points[1];
        c = points[3];
        d = points[2];

        double side1 = a.distanceTo(b);
        double side2 = b.distanceTo(c);
        double side3 = c.distanceTo(d);
        double side4 = d.distanceTo(a);

        double diagonal1 = a.distanceTo(c);

        bool oppositeSidesEqual = (side1 == side3 && side2 == side4);

        bool rightAngles = (sqrt(side1*side1 + side2*side2) == diagonal1);

        bool isRectangle = (rightAngles && oppositeSidesEqual);

        if (!isRectangle) {
            throw std::logic_error("Not a rectangle: sides are not equal or angles are not right");
        }
        
        _a = a;
        _b = b;
        _c = c;
        _d = d;
    }

    void operator=(const Rectangle<T>& right_operand)
    {
        _a = right_operand._a;
        _b = right_operand._b;
        _c = right_operand._c;
        _d = right_operand._d;
    }
    void operator=(Rectangle<T>&& right_operand)
    {
        _a = right_operand._a;
        _b = right_operand._b;
        _c = right_operand._c;
        _d = right_operand._d;
        right_operand._a = Point<T>();
        right_operand._b = Point<T>();
        right_operand._c = Point<T>();
        right_operand._d = Point<T>();
    }
    bool operator==(const Rectangle<T>& rpoint) const
    {
        return (
            _a == rpoint._a && 
            _b == rpoint._b && 
            _c == rpoint._c && 
            _d == rpoint._d
            );
    }

    explicit operator double() const //return surface
    {
        return surface();
    }
    
    virtual double surface() const override
    {
        double side1 = _a.distanceTo(_b);
        double side2 = _b.distanceTo(_c);
        return side1 * side2;
    }
    virtual Point<T> center() const override
    {
        double x_center = (_a.m_x + _b.m_x + _c.m_x + _d.m_x) / 4.0;
        double y_center = (_a.m_y + _b.m_y + _c.m_y + _d.m_y) / 4.0;
        return Point<T>(x_center, y_center);
    }

    virtual void printCout() const override
    {
        std::cout << "Rectangle: " << *this << std::endl;
    }
    virtual void readCin() override
    {
        while(true){ //until read the correct data  
            try{
                std::cout << "Enter 4 points for rectangle: " << std::endl;
                std::cin >> *this; 
                break;
            } catch(const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }

    //for testing
    Point<T> getA(){ return _a; }
    Point<T> getB(){ return _b; }
    Point<T> getC(){ return _c; }
    Point<T> getD(){ return _d; }

    virtual ~Rectangle() = default;
private: 
    Point<T> _a{0, 0};
    Point<T> _b{0, 0};
    Point<T> _c{0, 0};
    Point<T> _d{0, 0};
};