#include <gtest/gtest.h>
#include <string>
#include <memory>
#include "../include/stack.hpp"
#include "../include/allocator.hpp"


TEST(Iter, Test1) {
    Stack<int, Allocator<int, 15>> mystack;
    auto it = mystack.begin();
    
    EXPECT_ANY_THROW(*it);
}


TEST(Iter, Test2) {
    Stack<int, Allocator<int, 15>> mystack;
    auto it = mystack.begin();

    EXPECT_TRUE(it == nullptr);
}


TEST(Iter, Test3) {
    Stack<int, Allocator<int, 15>> mystack;
    auto it = mystack.end();
    auto it1 = mystack.begin();

    EXPECT_FALSE(it != it1);
}


TEST(Iter, Test4) {
    Stack<int, Allocator<int, 15>> mystack;
    auto it = mystack.end();

    EXPECT_ANY_THROW(*it);
}


TEST(Iter, Test5) {
    Stack<int, Allocator<int, 15>> mystack;
    for(size_t i{0}; i < 10; ++i) {
        mystack.push(10);
    }

    auto it = mystack.begin();
    EXPECT_EQ(mystack.top(), 10);
}


TEST(Iter, Test6) {
    Stack<int, Allocator<int, 15>> mystack;
    for(size_t i{0}; i < 10; ++i) {
        mystack.push(i);
    }

    auto it = mystack.begin();
    ++it;
    EXPECT_TRUE(*it == 8);
}


TEST(Iter, Test7) {
    Stack<int, Allocator<int, 15>> mystack;
    for(size_t i{0}; i < 10; ++i) {
        mystack.push(i);
    }

    testing::internal::CaptureStdout(); 
    for(auto it = mystack.begin(); it != mystack.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::string output = testing::internal::GetCapturedStdout(); 

    std::string res = "9 8 7 6 5 4 3 2 1 0 ";

    EXPECT_EQ(res, output);
}


TEST(Alloc, Test1) {
    EXPECT_THROW((Allocator<int, 0>{}), std::runtime_error);
}


TEST(Alloc, Test2) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }

    EXPECT_THROW(mystack.push(100), std::bad_alloc);
}


TEST(Alloc, Test3) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }
    for(int i = 0; i < 15; ++i) {
        mystack.pop();
    }
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }
    EXPECT_THROW(mystack.push(100), std::bad_alloc);
}

TEST(Alloc, Test4) {

    std::map<double, double, std::less<int>, Allocator<std::pair<const double, double>, 3>> test_map;
    test_map[1] = 2;
    test_map[2] = 3;
    test_map[3] = 5;

    testing::internal::CaptureStdout(); 
    for(const auto& [k,v]: test_map) {
            std::cout << k << " -> " << v << std::endl;
    } 
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << 1 << " -> " << 2 << std::endl;
    std::cout << 2 << " -> " << 3 << std::endl;
    std::cout << 3 << " -> " << 5 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(Alloc, Test5) {
    Allocator<int, 15> myallac;
    int* ptr = myallac.allocate(15);
    int* ptr1 = new int;
    myallac.deallocate(ptr, 1);

    EXPECT_THROW(myallac.deallocate(ptr1, 1), std::bad_alloc);
    EXPECT_THROW(myallac.deallocate(ptr, 1), std::bad_alloc);
}

TEST(Stack, Test1) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }

    EXPECT_EQ(mystack.top(), 14);
}

TEST(Stack, Test2) {
    Stack<int, Allocator<int, 15>> mystack;

    EXPECT_ANY_THROW(mystack.top());
}

TEST(Stack, Test4) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }
    for(int i = 0; i < 15; ++i) {
        mystack.pop();
    }

    EXPECT_ANY_THROW(mystack.pop());
}

TEST(Stack, Test5) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }

    EXPECT_THROW(mystack.push(321), std::bad_alloc);
}

TEST(Stack, Test6) {
    Stack<int, Allocator<int, 5>> mystack;
    EXPECT_EQ(mystack.size(), 0);
}

TEST(Stack, Test7) {
    Stack<int, Allocator<int, 15>> mystack;
    for(int i = 0; i < 15; ++i) {
        mystack.push(i);
    }

    EXPECT_EQ(mystack.size(), 15);
}

TEST(Stack, Test8) {
    Stack<std::map<std::string, int>, Allocator<std::map<std::string, int>, 15>> mystack;
    std::map<std::string, int> mymap;
    mymap["1"] = 1;
    mymap["2"] = 2;
    mymap["3"] = 3;
    mystack.push(mymap);

    auto mymap2 = mystack.top();
    EXPECT_EQ(mymap2["1"], 1);
    EXPECT_EQ(mymap2["2"], 2);
    EXPECT_EQ(mymap2["3"], 3);
    mystack.pop();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}