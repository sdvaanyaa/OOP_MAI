#include <gtest/gtest.h>
#include "../include/hearOfNum.h"  

TEST(test01, test_func){
    ASSERT_TRUE(hearOfNum("понедельник", 12));
}

TEST(test02, test_func){
    ASSERT_FALSE(hearOfNum("понедельник", -1500));
}

TEST(test03, test_func){
    ASSERT_TRUE(hearOfNum("вторник", 100));
}

TEST(test04, test_func){
    ASSERT_FALSE(hearOfNum("вторник", 0));
}

TEST(test05, test_func){
    ASSERT_TRUE(hearOfNum("среда", 34));
}

TEST(test06, test_func){
    ASSERT_FALSE(hearOfNum("среда", 1000-7));
}

TEST(test07, test_func){
    ASSERT_TRUE(hearOfNum("четверг", 0));
}

TEST(test08, test_func){
    ASSERT_FALSE(hearOfNum("четверг", 44));
}

TEST(test09, test_func){
    ASSERT_TRUE(hearOfNum("пятница", 88));
}

TEST(test10, test_func){
    ASSERT_FALSE(hearOfNum("пятница", 5555));
}

TEST(test11, test_func){
    ASSERT_TRUE(hearOfNum("суббота", 56));
}

TEST(test12, test_func){
    ASSERT_FALSE(hearOfNum("суббота", 10));
}

TEST(test13, test_func){
    ASSERT_TRUE(hearOfNum("воскресенье", 666));
}

TEST(test14, test_func){
    ASSERT_TRUE(hearOfNum("воскресенье", -666));
}

TEST(test15, test_func){
    ASSERT_FALSE(hearOfNum("воскресенье", -345678));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}