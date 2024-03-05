#include <gtest/gtest.h>
#include "../include/rectangle.hpp"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle<double> rectangle;
    ASSERT_EQ(Point(0.0, 0.0), rectangle.getA());
    ASSERT_EQ(Point(0.0, 0.0), rectangle.getB());
    ASSERT_EQ(Point(0.0, 0.0), rectangle.getC());
    ASSERT_EQ(Point(0.0, 0.0), rectangle.getD());
}

TEST(RectangleTest, ConstructorWithPoints) {
    Point a(-5.0, -7.0);
    Point b(0.0, -2.0);
    Point c(9.5, -11.5);
    Point d(4.5, -16.5);
    Rectangle rectangle(a, b, c, d);
    ASSERT_EQ(a, rectangle.getA());
    ASSERT_EQ(b, rectangle.getB());
    ASSERT_EQ(c, rectangle.getC());
    ASSERT_EQ(d, rectangle.getD());
}

TEST(RectangleTest, ConstructorWithPointsThrowsException) {
    Point a(1.0, 1.0);
    Point b(1.0, -45.0);
    Point c(2.0, 2.0);
    Point d(-2.0, 1.0);
    ASSERT_THROW(Rectangle rectangle(a, b, c, d), std::logic_error);
}

TEST(RectangleTest, AssignmentOperator) {
    Rectangle rectangle1(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));
    Rectangle<double> rectangle2;
    rectangle2 = rectangle1;
    ASSERT_EQ(rectangle1.getA(), rectangle2.getA());
    ASSERT_EQ(rectangle1.getB(), rectangle2.getB());
    ASSERT_EQ(rectangle1.getC(), rectangle2.getC());
    ASSERT_EQ(rectangle1.getD(), rectangle2.getD());
}

TEST(RectangleTest, MoveAssignmentOperator) {
    Point a(-5.0, -7.0);
    Point b(0.0, -2.0);
    Point c(9.5, -11.5);
    Point d(4.5, -16.5);
    Rectangle rectangle1(a, b, c, d);
    Rectangle<double> rectangle2;
    rectangle2 = std::move(rectangle1);
    EXPECT_EQ(a, rectangle2.getA());
    EXPECT_EQ(b, rectangle2.getB());
    EXPECT_EQ(c, rectangle2.getC());
    EXPECT_EQ(d, rectangle2.getD());
}

TEST(RectangleTest, ExplicitConversionToDouble) {
    Rectangle rectangle(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));   
    double surface = static_cast<double>(rectangle);
    ASSERT_DOUBLE_EQ(95.0, surface);
}

TEST(RectangleTest, OperatorEqual) {
    Rectangle rectangle1(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));
    Rectangle rectangle2(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));
    Rectangle rectangle3(Point(-1.0, -1.0), Point(-1.0, 1.0), Point(1.0, 1.0), Point(1.0, -1.0));
    ASSERT_EQ(rectangle1, rectangle2);
    ASSERT_NE(rectangle1, rectangle3);
}

TEST(RectangleTest, Surface) {
    Rectangle rectangle(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));
    double surface = rectangle.surface();
    EXPECT_DOUBLE_EQ(95.0, surface);

    Rectangle<int> rectangle0;
    double surface0 = rectangle0.surface();
    EXPECT_DOUBLE_EQ(0.0, surface0);
}

TEST(RectangleTest, Center) {
    Rectangle rectangle(Point(-5.0, -7.0), Point(0.0, -2.0), Point(9.5, -11.5), Point(4.5, -16.5));
    Point center = rectangle.center();
    EXPECT_EQ(Point(2.25, -9.25), center);

    Rectangle<int> rectangle0;
    Point center0 = rectangle0.center();
    EXPECT_EQ(Point(0, 0), center0);
}

