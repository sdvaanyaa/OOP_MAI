#pragma once

#include <string>
#include <iostream>

class HexArray
{ 
    public:
        HexArray();
        HexArray(const size_t & n, char t);
        HexArray(const size_t &n, int t);
        HexArray(const std::initializer_list< unsigned char> &t);
        HexArray(const std::string &t);
        HexArray(const HexArray& other);
        HexArray(HexArray&& other) noexcept;    
            
        
        bool     less(const HexArray& other);
        bool     greater(const HexArray& other);
        HexArray plus(const HexArray& other);
        HexArray minus(const HexArray& other);
        bool     equals(const HexArray& other) const;

        void     print();
        std::string str();
        
        virtual ~HexArray() noexcept;
        
        //for debug
        void           debugPrint();
        size_t         getSize();
        unsigned char* getArray();
        
    private:
        size_t _size;
        unsigned char *_array;
};

HexArray operator+(HexArray& lhs, const HexArray& rhs);
HexArray operator-(HexArray& lhs, const HexArray& rhs);
bool operator==(HexArray& lhs, const HexArray& rhs);
bool operator<(HexArray& lhs, const HexArray& rhs);
bool operator>(HexArray& lhs, const HexArray& rhs);