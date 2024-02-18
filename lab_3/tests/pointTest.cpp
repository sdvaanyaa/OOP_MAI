#include <gtest/gtest.h>
#include "../include/point.h"

TEST(PointTest, DefaultConstructor) {
    Point p;
    ASSERT_DOUBLE_EQ(p.m_x, 0.0);
    ASSERT_DOUBLE_EQ(p.m_y, 0.0);
}

TEST(PointTest, FillConstructor) {
    Point p(5, 3);
    ASSERT_DOUBLE_EQ(p.m_x, 5);
    ASSERT_DOUBLE_EQ(p.m_y, 3);
}

TEST(PointTest, InitializerListConstructor) {
    Point p = {1, -6};
    ASSERT_DOUBLE_EQ(p.m_x, 1);
    ASSERT_DOUBLE_EQ(p.m_y, -6);
}

TEST(PointTest, DistanceTo1) {
    Point p1 = {0, 0};
    Point p2 = {10, 0};
    double correctDisatance = 10.0;
    double distance = p1.distanceTo(p2);
    ASSERT_DOUBLE_EQ(distance, correctDisatance);
}

TEST(PointTest, DistanceTo2) {
    Point p1 = {-1, -5};
    Point p2 = {3, -2};
    double correctDisatance = 5.0;
    double distance = p1.distanceTo(p2);
    ASSERT_DOUBLE_EQ(distance, correctDisatance);
}

TEST(PointTest, OperatorEqual) {
    Point p1 = {1, 2};
    Point p2 = {1, 2};
    Point p3 = {4, 5};
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}

TEST(PointTest, OperatorEqualEmptyArray) {
    Point p1 = {-1, 2};
    Point p2 = {-1, 2};
    Point p3;
    Point p4;

    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
    ASSERT_TRUE(p3 == p4);
}

TEST(PointTest, OperatorOut) {
    testing::internal::CaptureStdout(); // Capture the output
    Point p(1, 2);
    std::cout << p;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    ASSERT_EQ(output, "[ x : 1, y : 2 ]");
}

TEST(PointTest, OperatorIn) {
    std::istringstream input("3.14 2.71"); // Create an input stream
    Point p;
    input >> p;

    ASSERT_DOUBLE_EQ(p.m_x, 3.14);
    ASSERT_DOUBLE_EQ(p.m_y, 2.71);
}