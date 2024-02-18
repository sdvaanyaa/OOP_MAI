#include "../include/trapezoid.h"
#include "../include/point.h"

#define POINT_COUNT 4

static bool isTrapezoid(Point a, Point b, Point c, Point d){
    bool parallelSides = ((b.m_x - c.m_x)*(a.m_y - d.m_y) == (a.m_x - d.m_x)*(b.m_y - c.m_y));
    bool sideSides = ((a.m_x - b.m_x)*(c.m_y - d.m_y) != (c.m_x - d.m_x)*(a.m_y - b.m_y));
	return (parallelSides && sideSides);
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d) {

    Point points[POINT_COUNT] = {a, b, c, d};
    std::sort(points, points + POINT_COUNT);
    a = points[0];
    b = points[1];
    c = points[2];
    d = points[3];

    if (isTrapezoid(a, b, c, d)) {
        _a = a;
        _b = b;
        _c = c;
        _d = d; 
        return;
    }
    if (isTrapezoid(a, b, d, c)){
        _a = a;
        _b = b;
        _c = d;
        _d = c;
        return;
    }

    if (!isTrapezoid(a, b, c, d) && !isTrapezoid(a, b, d, c)) {
        throw std::logic_error("Not a Trapezoid: sides are not equal or angles are not right");
    }

}

void Trapezoid::operator=(const Trapezoid& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
}

void Trapezoid::operator=(Trapezoid&& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
    right_operand._a = Point();
    right_operand._b = Point();
    right_operand._c = Point();
    right_operand._d = Point();
}

Trapezoid::operator double() const{
    return surface();
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& t) {
    os << "[ a : " << t._a << ", b : " << t._b << ", c : " << t._c << ", d : " << t._d << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& t) {
    Point a, b, c, d;
    is >> a >> b >> c >> d;
    t = Trapezoid(a, b, c, d);
    return is;
}

void Trapezoid::printCout() const {
    std::cout << "Trapezoid: " << *this << std::endl;
}

void Trapezoid::readCin(){
    while(true){ //until read the correct data  
        try{
            std::cout << "Enter 4 points for trapezoid: " << std::endl;
            std::cin >> *this; 
            break;
        } catch(const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

double Trapezoid::surface() const { 
    //a || b 
    double a = _b.distanceTo(_c);
    double b = _a.distanceTo(_d);

    double c = _a.distanceTo(_b);
    double d = _c.distanceTo(_d);

    if (a == 0){ //if Empty Trapezoid
        return 0.0;
    }
 
    double surface = (a + b) / 2 * sqrt(c * c - (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))) * (((a - b) * (a - b) + c * c - d * d) / (2 * (a  - b))));
    return surface;
}


Point Trapezoid::center() const {
    double x_center = (_a.m_x + _b.m_x + _c.m_x + _d.m_x) / 4.0;
    double y_center = (_a.m_y + _b.m_y + _c.m_y + _d.m_y) / 4.0;
    return Point(x_center, y_center);
}

bool Trapezoid::operator==(const Trapezoid& rpoint) const {
    return (
        _a == rpoint._a && 
        _b == rpoint._b && 
        _c == rpoint._c && 
        _d == rpoint._d
        );
}

Point Trapezoid::getA(){
    return _a;
}

Point Trapezoid::getB(){
    return _b;
}

Point Trapezoid::getC(){
    return _c;
}

Point Trapezoid::getD(){
    return _d;
}