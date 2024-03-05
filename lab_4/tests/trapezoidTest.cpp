#include <gtest/gtest.h>
#include "../include/trapezoid.hpp"

TEST(TrapezoidTest, DefaultConstructor) {
    Trapezoid<double> trapezoid;
    ASSERT_EQ(Point(0.0, 0.0), trapezoid.getA());
    ASSERT_EQ(Point(0.0, 0.0), trapezoid.getB());
    ASSERT_EQ(Point(0.0, 0.0), trapezoid.getC());
    ASSERT_EQ(Point(0.0, 0.0), trapezoid.getD());
}

TEST(TrapezoidTest, ConstructorWithPoints) {
    Point a(0.0, 0.0);
    Point b(1.0, 4.0);
    Point c(2.0, 4.0);
    Point d(3.0, 0.0);
    Trapezoid trapezoid(a, d, c, b);
    ASSERT_EQ(a, trapezoid.getA());
    ASSERT_EQ(b, trapezoid.getB());
    ASSERT_EQ(c, trapezoid.getC());
    ASSERT_EQ(d, trapezoid.getD());
}

TEST(TrapezoidTest, ConstructorWithPointsThrowsException) {
    Point a(1.0, 1.0);
    Point b(1.0, -45.0);
    Point c(2.0, 2.0);
    Point d(-2.0, 1.0);
    ASSERT_THROW(Trapezoid trapezoid(a, b, c, d), std::logic_error);
}

TEST(TrapezoidTest, AssignmentOperator) {
    Point a(1, 1);
    Point b(2, 2);
    Point c(4, 2);
    Point d(4, 1);
    Trapezoid trapezoid1(d, a, c, b);
    Trapezoid<int> trapezoid2;
    trapezoid2 = trapezoid1;
    ASSERT_EQ(trapezoid1.getA(), trapezoid2.getA());
    ASSERT_EQ(trapezoid1.getB(), trapezoid2.getB());
    ASSERT_EQ(trapezoid1.getC(), trapezoid2.getC());
    ASSERT_EQ(trapezoid1.getD(), trapezoid2.getD());
}

TEST(TrapezoidTest, MoveAssignmentOperator) {
    Point a(1.0, 1.0);
    Point b(2.0, 2.0);
    Point c(4.0, 2.0);
    Point d(4.0, 1.0);
    Trapezoid trapezoid1(d, b, c, a);
    Trapezoid<double> trapezoid2;
    trapezoid2 = std::move(trapezoid1);
    EXPECT_EQ(a, trapezoid2.getA());
    EXPECT_EQ(b, trapezoid2.getB());
    EXPECT_EQ(c, trapezoid2.getC());
    EXPECT_EQ(d, trapezoid2.getD());
}

TEST(TrapezoidTest, ExplicitConversionToDouble) {
    Point a(1.0, 1.0);
    Point b(2.0, 2.0);
    Point c(4.0, 2.0);
    Point d(4.0, 1.0);
    Trapezoid trapezoid(a, b, c, d);
    double surface = static_cast<double>(trapezoid);
    EXPECT_NEAR(2.5, surface, 1e-6); 
}

TEST(TrapezoidTest, OperatorEqual) {
    Point a(1.0, 1.0);
    Point b(2.0, 2.0);
    Point c(4.0, 2.0);
    Point d(4.0, 1.0);
    Trapezoid trapezoid1(a, b, c, d);
    Trapezoid trapezoid2(a, d, b, c);
    Trapezoid trapezoid3(Point(-1.0, -1.0), Point(0.0, 3.0), Point(8.0, 3.0), Point(99.0, -1.0));
    ASSERT_EQ(trapezoid1, trapezoid2);
    ASSERT_NE(trapezoid1, trapezoid3);
}

TEST(TrapezoidTest, Surface) {
    Point a(1.0, 1.0);
    Point b(2.0, 2.0);
    Point c(4.0, 2.0);
    Point d(4.0, 1.0);
    Trapezoid trapezoid(a, b, c, d);
    double surface = trapezoid.surface();
    EXPECT_NEAR(2.5, surface, 1e-6);

    Trapezoid<int64_t> trapezoid0;
    double surface0 = trapezoid0.surface();
    EXPECT_DOUBLE_EQ(0.0, surface0);
}

TEST(TrapezoidTest, Center) {
    Point a(1.0, 1.0);
    Point b(2.0, 2.0);
    Point c(4.0, 2.0);
    Point d(4.0, 1.0);
    Trapezoid trapezoid(a, b, c, d);
    Point center = trapezoid.center();
    EXPECT_EQ(Point(2.75, 1.5), center);

    Trapezoid<double> trapezoid0;
    Point center0 = trapezoid0.center();
    EXPECT_EQ(Point(0.0, 0.0), center0);
}



