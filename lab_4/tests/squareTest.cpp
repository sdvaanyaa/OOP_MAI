#include <gtest/gtest.h>
#include "../include/square.hpp"

TEST(SquareTest, DefaultConstructor) {
    Square<double> square;
    ASSERT_EQ(Point(0.0, 0.0), square.getA());
    ASSERT_EQ(Point(0.0, 0.0), square.getB());
    ASSERT_EQ(Point(0.0, 0.0), square.getC());
    ASSERT_EQ(Point(0.0, 0.0), square.getD());
}

TEST(SquareTest, ConstructorWithPoints) {
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c(2.0, 2.0);
    Point d(2.0, 1.0);
    Square square(a, b, c, d);
    ASSERT_EQ(a, square.getA());
    ASSERT_EQ(b, square.getB());
    ASSERT_EQ(c, square.getC());
    ASSERT_EQ(d, square.getD());
}

TEST(SquareTest, ConstructorWithPointsThrowsException) {
    Point a(1.0, 1.0);
    Point b(1.0, -45.0);
    Point c(2.0, 2.0);
    Point d(-2.0, 1.0);
    ASSERT_THROW(Square square(a, b, c, d), std::logic_error);
}

TEST(SquareTest, AssignmentOperator) {
    Square square1(Point(1, 1), Point(1, 2), Point(2, 2), Point(2, 1));
    Square<int> square2;
    square2 = square1;
    ASSERT_EQ(square1.getA(), square2.getA());
    ASSERT_EQ(square1.getB(), square2.getB());
    ASSERT_EQ(square1.getC(), square2.getC());
    ASSERT_EQ(square1.getD(), square2.getD());
}

TEST(SquareTest, MoveAssignmentOperator) {
    Point a(1.0, 1.0);
    Point b(1.0, 2.0);
    Point c(2.0, 2.0);
    Point d(2.0, 1.0);
    Square square1(a, b, c, d);
    Square<double> square2;
    square2 = std::move(square1);
    EXPECT_EQ(a, square2.getA());
    EXPECT_EQ(b, square2.getB());
    EXPECT_EQ(c, square2.getC());
    EXPECT_EQ(d, square2.getD());
}

TEST(SquareTest, ExplicitConversionToDouble) {
    Square square(Point(1.0, 1.0), Point(1.0, 2.0), Point(2.0, 2.0), Point(2.0, 1.0));
    double surface = static_cast<double>(square);
    ASSERT_DOUBLE_EQ(1.0, surface);
}

TEST(SquareTest, OperatorEqual) {
    Square square1(Point(1.0, 1.0), Point(1.0, 2.0), Point(2.0, 2.0), Point(2.0, 1.0));
    Square square2(Point(1.0, 1.0), Point(1.0, 2.0), Point(2.0, 2.0), Point(2.0, 1.0));
    Square square3(Point(-1.0, -1.0), Point(-1.0, 1.0), Point(1.0, 1.0), Point(1.0, -1.0));
    ASSERT_EQ(square1, square2);
    ASSERT_NE(square1, square3);
}

TEST(SquareTest, Surface) {
    Square square(Point(1.0, 1.0), Point(1.0, 2.0), Point(2.0, 2.0), Point(2.0, 1.0));
    double surface = square.surface();
    EXPECT_DOUBLE_EQ(1.0, surface);

    Square<float> square0;
    double surface0 = square0.surface();
    EXPECT_DOUBLE_EQ(0.0, surface0);
}

TEST(SquareTest, Center) {
    Square square(Point(1.0, 1.0), Point(1.0, 2.0), Point(2.0, 2.0), Point(2.0, 1.0));
    Point center = square.center();
    EXPECT_EQ(Point(1.5, 1.5), center);

    Square<int> square0;
    Point center0 = square0.center();
    EXPECT_EQ(Point(0, 0), center0);
}

