#include <gtest/gtest.h>
#include "../include/HexArray.h"

TEST(HexArrayTest, DefaultConstructor) {
    HexArray hx;
    ASSERT_EQ(hx.getSize(), 0);
    ASSERT_EQ(hx.getArray(), nullptr);
}

TEST(HexArrayTest, FillConstructorInt) {
    HexArray hx(5, 3);
    ASSERT_EQ(hx.getSize(), 5);
    unsigned char* arr = hx.getArray();
    for(size_t i = 0; i < 5; ++i)
        ASSERT_EQ(arr[i], 3);
}

TEST(HexArrayTest, FillConstructorChar) {
    HexArray hx(5, 'A');
    ASSERT_EQ(hx.getSize(), 5);
    unsigned char* arr = hx.getArray();
    for(size_t i = 0; i < 5; ++i)
        ASSERT_EQ(arr[i], 'A');
}

TEST(HexArrayTest, FillConstructorCharThrowsException) {
    ASSERT_THROW(HexArray hx(5, 'Z'), std::logic_error);
}

TEST(HexArrayTest, FillConstructorIntThrowsException) {
    ASSERT_THROW(HexArray hx(5, -45), std::logic_error);
}

TEST(HexArrayTest, InitializerListConstructor) {
    HexArray hx = {1, 2, 3, 4};
    ASSERT_EQ(hx.getSize(), 4);
    unsigned char* arr = hx.getArray();
    for(size_t i = 0; i < 4; ++i)
        ASSERT_EQ(arr[i], i + 1);
}

TEST(HexArrayTest, CopyStringConstructor1) {
    std::string str = "1F3A";
    HexArray hx(str);
    size_t hxSize = hx.getSize();
    ASSERT_EQ(hxSize, 4);
    unsigned char* arr = hx.getArray();
    ASSERT_EQ(str, hx.str());
}

TEST(HexArrayTest, CopyStringConstructor2) {
    std::string str = "1000";
    HexArray hx(str);
    size_t hxSize = hx.getSize();
    ASSERT_EQ(hxSize, 4);
    unsigned char* arr = hx.getArray();
    ASSERT_EQ(str, hx.str());
}

TEST(HexArrayTest, CopyStringConstructorThrowsException1) {
    std::string str = "0AD1";
    EXPECT_THROW(HexArray hx(str), std::logic_error);
}

TEST(HexArrayTest, CopyStringConstructorThrowsException2) {
    std::string str = "В*01.";
    EXPECT_THROW(HexArray hx(str), std::logic_error);
}

TEST(HexArrayTest, CopyConstructor) {
    HexArray hx1 = {1, 2, 3, 4};
    HexArray hx2(hx1);
    ASSERT_TRUE(hx1 == hx2);
}

TEST(HexArrayTest, MoveConstructor1) {
    HexArray hx1 = {1, 2, 3, 4};
    HexArray hx2(std::move(hx1));
    ASSERT_EQ(hx1.getSize(), 0);
    ASSERT_EQ(hx1.getArray(), nullptr);
    ASSERT_EQ(hx2.getSize(), 4);
    unsigned char* arr = hx2.getArray();
    for(size_t i = 0; i < 4; ++i)
        ASSERT_EQ(arr[i], i + 1);
}

TEST(HexArrayTest, MoveConstructor2) {
    HexArray hx1;
    HexArray hx2(std::move(hx1));
    ASSERT_EQ(hx1.getSize(), 0);
    ASSERT_EQ(hx1.getArray(), nullptr);
    ASSERT_EQ(hx2.getSize(), 0);
    ASSERT_EQ(hx2.getArray(), nullptr);
}

TEST(HexArrayTest, PlusOperator1) {
    HexArray hx1 = {1, 1, 1, 15};
    HexArray hx2 = {12, 4, 8, 15};
    HexArray correctSum = {13, 5, 9, 14, 1};
    HexArray sum = hx1 + hx2;
    ASSERT_TRUE(sum.equals(correctSum));
}

//verified by the calculator
TEST(HexArrayTest, PlusOperator2) {
    HexArray hx1("8AB");
    HexArray hx2("B78");
    HexArray correctSum("1423");
    HexArray sum = hx1 + hx2;
    ASSERT_TRUE(sum == correctSum);
}

//verified by the calculator
TEST(HexArrayTest, PlusOperator3) {
    HexArray hx1("FFFFFEC0");
    HexArray hx2("CACACAB22");
    HexArray correctSum("DACACA9E2");
    HexArray sum = hx1 + hx2;
    ASSERT_TRUE(sum == correctSum);
}

TEST(HexArrayTest, PlusOperatorEmptyArray1) {
    HexArray hx1 = {1, 1, 1, 15};
    HexArray hx2;
    HexArray correctSum = {1, 1, 1, 15};
    HexArray sum = hx1 + hx2;
    ASSERT_TRUE(sum.equals(correctSum));
}

TEST(HexArrayTest, PlusOperatorEmptyArray2) {
    HexArray hx1;
    HexArray hx2;
    HexArray correctSum;
    HexArray sum = hx1 + hx2;
    ASSERT_TRUE(sum.equals(correctSum));
}

TEST(HexArrayTest, MinusOperator1) {
    HexArray hx1 = {1, 1, 9, 15};
    HexArray hx2 = {12, 4, 8, 15};
    HexArray correctDiff = {5, 12};
    HexArray diff = hx1 - hx2;
    ASSERT_TRUE(diff.equals(correctDiff));
}

//verified by the calculator
TEST(HexArrayTest, MinusOperator2) {
    HexArray hx1("FFFFFEC0");
    HexArray hx2("CACACAB2");
    HexArray correctDiff("3535340E");
    HexArray diff = hx1 - hx2;
    ASSERT_TRUE(diff.equals(correctDiff));
}

TEST(HexArrayTest, MinusOperatorEmptyArray1) {
    HexArray hx1 = {1, 1, 9, 15};
    HexArray hx2;
    HexArray correctDiff = {1, 1, 9, 15};
    HexArray diff = hx1 - hx2;
    ASSERT_TRUE(diff.equals(correctDiff));
}

TEST(HexArrayTest, MinusOperatorEmptyArray2) {
    HexArray hx1;
    HexArray hx2;
    HexArray correctDiff;
    HexArray diff = hx1 - hx2;
    ASSERT_TRUE(diff.equals(correctDiff));
}

TEST(HexArrayTest, MinusOperatorThrowsException) {
    HexArray hx1 = {1, 1, 0, 1};
    HexArray hx2 = {12, 4, 8, 15, 1};
    EXPECT_THROW(hx1 - hx2, std::logic_error);
}

TEST(HexArrayTest, EqualsFunction) {
    HexArray hx1 = {1, 2, 3};
    HexArray hx2 = {1, 2, 3};
    HexArray hx3 = {4, 5, 6};
    ASSERT_TRUE(hx1.equals(hx2));
    ASSERT_FALSE(hx1.equals(hx3));
}

TEST(HexArrayTest, EqualsFunctionEmptyArray) {
    HexArray hx1 = {1, 2, 3};
    HexArray hx2 = {1, 2, 3};
    HexArray hx3;
    HexArray hx4;
    ASSERT_TRUE(hx1.equals(hx2));
    ASSERT_FALSE(hx1.equals(hx3));
    ASSERT_TRUE(hx3 == hx4);
}

TEST(HexArrayTest, PrintFunction) {
    testing::internal::CaptureStdout(); // Capture the output
    HexArray hx("123");
    hx.print();
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    ASSERT_EQ(output, "123\n");
}

TEST(HexArrayTest, PrintFunctionEmptyArray) {
    testing::internal::CaptureStdout(); // Capture the output
    HexArray hx;
    hx.print();
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    ASSERT_EQ(output, "\n");
}

TEST(HexArrayTest, DestructorTest) {
    HexArray myObject("FFFFFEC0FFFFFEC0");

    // Ожидаем, что при удалении объекта произойдет вызов деструктора
    EXPECT_DEATH(delete &myObject, "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}