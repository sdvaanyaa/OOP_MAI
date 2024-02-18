#include "../include/rectangle.h"
#include "../include/point.h"

#define POINT_COUNT 4

Rectangle::Rectangle(Point a, Point b, Point c, Point d) {

    Point points[POINT_COUNT] = {a, b, c, d};
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

std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << "[ a : " << r._a << ", b : " << r._b << ", c : " << r._c << ", d : " << r._d << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& r) {
    Point a, b, c, d;
    is >> a >> b >> c >> d;
    r = Rectangle(a, b, c, d);
    return is;
}

void Rectangle::printCout() const {
    std::cout << "Rectangle: " << *this << std::endl;
}

void Rectangle::readCin(){
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

void Rectangle::operator=(const Rectangle& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
}
void Rectangle::operator=(Rectangle&& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
    right_operand._a = Point();
    right_operand._b = Point();
    right_operand._c = Point();
    right_operand._d = Point();
}

Rectangle::operator double() const{
    return surface();
}

bool Rectangle::operator==(const Rectangle& rpoint) const {
    return (
        _a == rpoint._a && 
        _b == rpoint._b && 
        _c == rpoint._c && 
        _d == rpoint._d
        );
}

Point Rectangle::getA(){
    return _a;
}

Point Rectangle::getB(){
    return _b;
}

Point Rectangle::getC(){
    return _c;
}

Point Rectangle::getD(){
    return _d;
}


double Rectangle::surface() const {
    double side1 = _a.distanceTo(_b);
    double side2 = _b.distanceTo(_c);
    return side1 * side2;
}

Point Rectangle::center() const {
    double x_center = (_a.m_x + _b.m_x + _c.m_x + _d.m_x) / 4.0;
    double y_center = (_a.m_y + _b.m_y + _c.m_y + _d.m_y) / 4.0;
    return Point(x_center, y_center);
}