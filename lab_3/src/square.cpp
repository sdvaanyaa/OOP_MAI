#include "../include/square.h"
#include "../include/point.h"

#define POINT_COUNT 4

Square::Square(Point a, Point b, Point c, Point d){
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

	double diagonal = a.distanceTo(c);

	bool sidesEqual = (side1 == side2 && side2 == side3 && side3 == side4);

	//check through the pythagorean theorems
	bool rightAngles = (sqrt(side1*side1 + side2*side2) == diagonal);

	if (!sidesEqual || !rightAngles)  {
		throw std::logic_error("not square: sides are not equal");
	} 
    
	_a = a;
	_b = b;
	_c = c;
	_d = d;
}

void Square::operator=(const Square& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
}

void Square::operator=(Square&& right_operand){
    _a = right_operand._a;
    _b = right_operand._b;
    _c = right_operand._c;
    _d = right_operand._d;
    right_operand._a = Point();
    right_operand._b = Point();
    right_operand._c = Point();
    right_operand._d = Point();
}

Square::operator double() const{
    return surface();
}

std::ostream& operator<<(std::ostream& os, const Square& t){
	os << "[ a : " << t._a << ", b : " << t._b << ", c : " << t._c << ", d : " << t._d << "]";	
	return os;
}

std::istream& operator>>(std::istream& is, Square& t){
    Point a, b, c, d;
    is >> a >> b >> c >> d;
	t = Square(a, b, c, d);	
	return is;
}

void Square::printCout() const {
    std::cout << "Square: " << *this << std::endl;
}

void Square::readCin(){
    while(true){ //until read the correct data  
        try{
            std::cout << "Enter 4 points for square: " << std::endl;
            std::cin >> *this; 
            break;
        } catch(const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

double Square::surface() const {
    double a = _a.distanceTo(_b); 
	return a*a;
}

Point Square::center() const {
     double x_center = (_a.m_x + _b.m_x + _c.m_x + _d.m_x) / 4.0;
    double y_center = (_a.m_y + _b.m_y + _c.m_y + _d.m_y) / 4.0;
    return Point(x_center, y_center);
}

bool Square::operator==(const Square& rpoint) const {
    return (
        _a == rpoint._a && 
        _b == rpoint._b && 
        _c == rpoint._c && 
        _d == rpoint._d
        );
}

Point Square::getA(){
    return _a;
}

Point Square::getB(){
    return _b;
}

Point Square::getC(){
    return _c;
}

Point Square::getD(){
    return _d;
}