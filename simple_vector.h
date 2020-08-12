#pragma once

#include <cstdlib>

template<typename T>
class SimpleVector {
public:
    SimpleVector();
    explicit SimpleVector(size_t size);

    ~SimpleVector();

    T &operator[](size_t index);

    T *begin();
    T *end();

    const T *begin() const;
    const T *end() const;

    size_t Size() const;
    size_t Capacity() const;

    void PushBack(const T &value);

private:
    T *_data;
    size_t _capacity;
    size_t _size;
};