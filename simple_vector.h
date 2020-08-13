#pragma once

#include <cstdlib>
#include <algorithm>

template<typename T>
class SimpleVector {
public:
    SimpleVector();
    explicit SimpleVector(size_t size);
    SimpleVector(const SimpleVector& rhs);
    void operator=(const SimpleVector& rhs);

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



template<typename T>
SimpleVector<T>::SimpleVector() :
        _data(nullptr),
        _capacity(0),
        _size(0)
{
}

template<typename T>
SimpleVector<T>::SimpleVector(size_t size) :
        _data(new T[size]),
        _capacity(size),
        _size(size)
{
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& rhs) :
        _data(new T[rhs._capacity]),
        _capacity(rhs._capacity),
        _size(rhs._size)
{
    std::copy(rhs.begin(), rhs.end(), begin());
}

template<typename T>
void SimpleVector<T>::operator=(const SimpleVector &rhs) {
    if (rhs._size < _capacity) {
        std::copy(rhs.begin(), rhs.end(), begin());
    } else {
        SimpleVector<T> tmp(rhs);
        std::swap(tmp._data, _data);
        std::swap(tmp._capacity, _capacity);
        std::swap(tmp._size, _size);
    }
}

template<typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] _data;
}

template<typename T>
T &SimpleVector<T>::operator[](size_t index) {
    return _data[index];
}

template<typename T>
T *SimpleVector<T>::begin() {
    return _data;
}

template<typename T>
T *SimpleVector<T>::end() {
    return _data + _size;
}

template<typename T>
const T *SimpleVector<T>::begin() const {
    return _data;
}

template<typename T>
const T *SimpleVector<T>::end() const {
    return _data + _size;
}

template<typename T>
size_t SimpleVector<T>::Size() const {
    return _size;
}

template<typename T>
size_t SimpleVector<T>::Capacity() const {
    return _capacity;
}

template<typename T>
void SimpleVector<T>::PushBack(const T &value) {
    if (_size == _capacity) {
        _capacity = _capacity == 0 ? 1 : 2 * _capacity;

        T *tmp_data = new T[_capacity];

        for (int i = 0; i < _size; ++i) {
            tmp_data[i] = _data[i];
        }

        delete[] _data;
        _data = tmp_data;
    }

    _data[_size] = value;
    ++_size;
}

