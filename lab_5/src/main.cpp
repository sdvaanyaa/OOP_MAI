#include "../include/allocator.hpp"
#include "../include/stack.hpp"
#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {

    std::map<int, int, std::less<int>, Allocator<std::pair<const int,int>, 10>> my_map;
    
    std::cout << "Allocator checking for std::map" << std::endl;
    
    for (size_t i = 0; i < 10; ++i) {
        my_map[i] = fact(i);
    }

    for(const auto& [k,v]: my_map) {
        std::cout << k << " -> " << v << std::endl;
    } 

    std::cout << "Allocator checking for my Stack " << std::endl; 

    Stack<int, Allocator<int, 10000>> stack;
    std::size_t elem_count;
    std::cout << "Enter elements count: ";
    std::cin >> elem_count;
    int n;
    for (size_t i = 0; i < elem_count; i++) {    
        std::cout << "Enter the integer number: ";
        std::cin >> n;
        stack.push(n);
    }

    for (auto i = stack.begin(); i != stack.end(); ++i) {
        std::cout << *i << std::endl;
    }        
    std::cout << "Checking is done" << std::endl;

    return 0;
}