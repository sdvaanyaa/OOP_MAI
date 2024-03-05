#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <vector>
#include <utility>
#include <map>

template <class T, size_t BLOCK_COUNT>
class Allocator
{
private:
    T* _buffer;
    std::map<T*, bool> _used_blocks;
    std::vector<T*> _free_blocks;

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Allocator()
    {
        if (BLOCK_COUNT == 0)
        {
            throw (std::runtime_error("BLOCK_COUNT == 0"));
        }

        _buffer = new T[BLOCK_COUNT];
        
        for (size_t i = 0; i < BLOCK_COUNT; i++)
        {
            _free_blocks.push_back(&_buffer[i]);
        }
    }

    ~Allocator(){
        delete[] _buffer;
    }

    template <class U>
    struct rebind
    {
        using other = Allocator<U, BLOCK_COUNT>;
    };

    T* allocate(size_t)
    {
		if (_free_blocks.size() == 0) {
			throw(std::bad_alloc());
		} 

        T* p = _free_blocks.back(); 
        _free_blocks.pop_back();

        _used_blocks[p] = true;
        return p;
    }

    void deallocate(T *pointer, size_t)
    {
        if (_used_blocks[pointer] == false)
        {
            throw (std::bad_alloc());
        }
        _free_blocks.push_back(pointer); 
        _used_blocks[pointer] = false;
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p)
    {
        p->~T();
    }
};

