#include "../include/HexArray.h" 

static bool isHexSymbolChar(unsigned char c){
    if ((c >= '0' and c <= '9') or (c >= 'A' and c <= 'F')) return true;
    return false;
}

static bool isHexSymbolInt(int c){
    if (c >= 0 and c < 16) return true;
    return false;
}

HexArray::HexArray() : _size(0), _array{nullptr}
{
    // std::cout << "Default constructor" << std::endl;
}

HexArray::HexArray(const size_t &n, char t)
{
    // std::cout << "Fill constructor" << std::endl;

    if (!isHexSymbolChar(t)) throw std::logic_error("not a hex-number: unknown character in hex: " + t);

    int value = (t >= '0' && t <= '9') ? (t - '0') : (t - 'A' + 10);

    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = value;
    _size = n;
}

HexArray::HexArray(const size_t &n, int t)
{
    // std::cout << "Fill constructor" << std::endl;

    if (!isHexSymbolInt(t)) throw std::logic_error("not a hex-number: unknown character in hex: " + t);

    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

HexArray::HexArray(const std::initializer_list<unsigned char> &t)
{
    // std::cout << "Initializer list constructor" << std::endl;
    _array = new unsigned char[t.size()];
    size_t i{0};
    for (auto c : t)
        _array[i++] = c;
    _size = t.size();
}

HexArray::HexArray(const std::string &t)
{
    // std::cout << "Copy string constructor" << std::endl;
    _array = new unsigned char[t.size()];
    _size  = t.size();

    // for(size_t i{0};i<_size;++i) _array[i] = t[i];

    if (t[0] == '0' and _size > 1) {throw std::logic_error("not a hex-number: zero at the beginning");}

    for (size_t i = 0; i < _size; ++i)
    {
        if (!isHexSymbolChar(t[_size-1 - i])) 
            throw std::logic_error("not a hex-number: unknown character in hex: " + t[_size-1 - i]);

        if (t[_size-1 - i] <= 57) _array[i] = t[_size-1 - i] - '0';
        else _array[i] = t[_size-1 - i] - 'A' + 10;
    }
}

HexArray::HexArray(const HexArray &other)
{
    // std::cout << "Copy constructor" << std::endl;
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

HexArray::HexArray(HexArray &&other) noexcept
{
    // std::cout << "Move constructor" << std::endl;
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

bool HexArray::less(const HexArray& other){
    if (_size < other._size) return true;
    if (_size > other._size) return false;
    for (int i = _size-1; i >= 0; --i)
    {
        if (_array[i] > other._array[i]) return false;
        if (_array[i] < other._array[i]) return true;
    }
    return false;
}

bool HexArray::greater(const HexArray& other){
    if (_size > other._size) return true;
    if (_size < other._size) return false;
    for (int i = _size-1; i >= 0; --i)
    {
        if (_array[i] < other._array[i]) return false;
        if (_array[i] > other._array[i]) return true;
    }
    return false;
}

bool HexArray::equals(const HexArray &other) const
{
    if (_size != other._size) return false;
    for (size_t i = 0; i < _size; ++i){
        if (_array[i] != other._array[i]) return false;
    }
    return true;
}

HexArray HexArray::plus(const HexArray &other)
{
    int minSize = std::min(_size, other._size);
    int maxSize = std::max(_size, other._size);
    if (minSize == 0) return _size == 0 ? other : *this;

    HexArray result(maxSize, 0); 
    unsigned char surPlus {0};
    for (int i {0}; i < minSize; ++i){
        int sum = _array[i] + other._array[i] + surPlus;
        if (sum > 0xF) {
            result._array[i] = sum - 0xF - 1;
            surPlus = 1;
        } else {
            result._array[i] = sum;
            surPlus = 0;
        }
    }
    
    HexArray maxArray = (_size < other._size) ? other : *this;

    if (surPlus > 0) {
        if (minSize == maxSize) {
            unsigned char* tmp = new unsigned char[maxSize+1];
            for (int i {0}; i < maxSize; ++i){
                tmp[i] = result._array[i];
            }
            tmp[maxSize] = surPlus;
            result._array = tmp;
            result._size++;
            return result;
        }
        else if (maxArray._array[maxSize-1] == 0xF){
            unsigned char* tmp = new unsigned char[maxSize+1];
            for (int i {0}; i < maxSize; ++i){
                tmp[i] = result._array[i];
            }
            result._array = tmp;
            result._size++;
        }
        for (int i {minSize}; i < maxArray._size; ++i){
            int sum = maxArray._array[i] + surPlus;
            if (sum > 0xF) {
                result._array[i] = sum - 0xF - 1;
                surPlus = 1;
            } else {
                result._array[i] = sum;
                surPlus = 0;
            }
        }
    }
    else {
        for (int i {minSize}; i < maxArray._size; ++i){
            result._array[i] = maxArray._array[i];
        }
    }
    return result;
}

HexArray HexArray::minus(const HexArray &other)
{
    if (*this < other) 
        throw std::logic_error("remove: subtracting a large number from a smaller one");
    
    HexArray result(_size, 0); 
    int surMinus = 0;
    for (int i = 0; i < other._size; ++i){
        int dif = _array[i] - other._array[i] - surMinus;
        if (dif < 0){
            result._array[i] = 0xF + dif + 1;
            surMinus = 1;
        } else {
            result._array[i] = dif;
            surMinus = 0;
        }
    }
    for (int i = other._size; i < _size; ++i){
        int dif = _array[i] - surMinus;
        if (dif < 0){
            result._array[i] = 0xF + dif + 1;
            surMinus = 1;
        } else {
            result._array[i] = dif;
            surMinus = 0;
        }
    }
    
    for (int i = result._size-1; i >= 0; --i)    {
        if (result._array[i] == 0) result._size--;
        else break;
    }
    if (result._size == 0){
        delete[] result._array;
        result._array = nullptr;
    }

    return result;
}

void HexArray::print()
{
    for (int i = _size-1; i >= 0; --i)
    {
        if (_array[i] <= 9) std::cout << (char)(_array[i] + '0');
        else std::cout << (char)(_array[i] + 'A'-10);
    }
    std::cout << std::endl;
}

void HexArray::debugPrint()
{
    for (int i = 0; i < _size; ++i)
    {
        std::cout << (int)_array[i] << ' ';
    }
    std::cout << std::endl;
}

std::string HexArray::str(){
    char charArr[_size];
    for (int i = 0; i < _size; ++i)
    {
        if (_array[_size-i-1] <= 9) charArr[i] = (_array[_size-i-1] + '0');
        else charArr[i] = (_array[_size-i-1] + 'A'-10);
    }
    std::string str(charArr, _size);
    return str;
}

HexArray::~HexArray() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

size_t HexArray::getSize(){
    return _size;
}

unsigned char* HexArray::getArray(){
    return _array;
}

HexArray operator+(HexArray& lhs, const HexArray& rhs)
{
    return lhs.plus(rhs);
}

HexArray operator-(HexArray& lhs, const HexArray& rhs)
{
    return lhs.minus(rhs);
}

bool operator==(HexArray& lhs, const HexArray& rhs)
{
    return lhs.equals(rhs);
}

bool operator<(HexArray& lhs, const HexArray& rhs)
{
    return lhs.less(rhs);
}

bool operator>(HexArray& lhs, const HexArray& rhs)
{
    return lhs.greater(rhs);
}
