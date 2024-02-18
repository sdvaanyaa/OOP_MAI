#include "../include/point.h"
#include <iostream>

Point::Point(double x ,double y): m_x(x), m_y(y) {};

std::ostream& operator<<(std::ostream& os , const Point& point){
	os << "[ x : " << point.m_x << ", y : " << point.m_y << " ]";
	return os;
}

std::istream& operator>>(std::istream& is, Point& point){
    double x, y;
    is >> x >> y;
    point.m_x = x;
    point.m_y = y;
    return is;
}

Point& Point::operator=(const Point& right_operand){
    if(this!= &right_operand){
            m_x = right_operand.m_x;
            m_y = right_operand.m_y; 
    }
    return *this;
}

bool Point::operator==(const Point& rpoint) const {
    return (m_x == rpoint.m_x && m_y == rpoint.m_y);
}

double Point::distanceTo(const Point& rpoint) const {
    double distance = sqrt(((m_x - rpoint.m_x) * (m_x - rpoint.m_x)) + ((m_y - rpoint.m_y) * (m_y - rpoint.m_y)));
    return distance;
}
bool Point::operator<(const Point& rpoint) const {
    if (m_x != rpoint.m_x) {
        return m_x < rpoint.m_x;
    }
    return m_y < rpoint.m_y;
}

bool Point::operator>(const Point& rpoint) const {
    if (m_x != rpoint.m_x) {
        return m_x > rpoint.m_x;
    }
    return m_y > rpoint.m_y;
}