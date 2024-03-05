#pragma once
#include <iostream>
#include <math.h>

template <typename T>
concept Number = std::is_default_constructible<T>::value || std::integral<T> || std::floating_point<T>;

template <Number T>
class Point
{
    friend std::ostream &operator<<(std::ostream &os, const Point<T> &point)
    {
        os << "[ x : " << point.m_x << ", y : " << point.m_y << " ]";
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Point<T> &point)
    {
        double x, y;
        is >> x >> y;
        point.m_x = x;
        point.m_y = y;
        return is;
    }

public:
    Point() = default;
    Point(T x, T y) : m_x(x), m_y(y){};
    ~Point() = default;

    T m_x{0};
    T m_y{0};

    Point &operator=(const Point<T> &right_operand)
    {
        if (this != &right_operand)
        {
            m_x = right_operand.m_x;
            m_y = right_operand.m_y;
        }
        return *this;
    }
    bool operator==(const Point<T> &rpoint)
        const
    {
        return (m_x == rpoint.m_x && m_y == rpoint.m_y);
    }
    bool operator<(const Point<T> &rpoint) const
    {
        if (m_x != rpoint.m_x)
        {
            return m_x < rpoint.m_x;
        }
        return m_y < rpoint.m_y;
    }
    bool operator>(const Point<T> &rpoint) const
    {
        if (m_x != rpoint.m_x)
        {
            return m_x > rpoint.m_x;
        }
        return m_y > rpoint.m_y;
    }

    double distanceTo(const Point<T> &rpoint) const
    {
        double distance = sqrt(((m_x - rpoint.m_x) * (m_x - rpoint.m_x)) + ((m_y - rpoint.m_y) * (m_y - rpoint.m_y)));
        return distance;
    }
};