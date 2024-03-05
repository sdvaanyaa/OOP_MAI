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

    std::vector<T*> allocate(size_t count) {
        std::vector<T*> allocatedBlocks;

        for (size_t i = 0; i < count; ++i) {
            if (_free_blocks.size() == 0) {
                throw std::bad_alloc();
            }

            T* p = _free_blocks.back();
            _free_blocks.pop_back();

            _used_blocks[p] = true;
            allocatedBlocks.push_back(p);
        }

        return allocatedBlocks;
    }

    void deallocate(size_t blockSize) {
        const auto& blocks = _allocated_blocks[blockSize];

        for (T* p : blocks) {
            _free_blocks[blockSize].push_back(p);
            _used_blocks[p] = false;
        }

        _allocated_blocks[blockSize].clear();
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

