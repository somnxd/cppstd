#pragma once

#include <cstddef>
#include <stdexcept>

template<typename T>
class Vector {
public:
    // add items

    void append(const T &item) noexcept {
        if (this->length == this->capacity)
            this->resize();

        this->array[this->length] = item;
        this->length++;
    }

    // remove items

    void pop() noexcept {
        this->length--;
    }

    void pop(const size_t index) noexcept {
        if (index >= this->length)
            throw std::out_of_range("index out of range");

        for (size_t i = index + 1; i < this->length; i++)
            this->array[i - 1] = this->array[i];

        this->length--;
    }

    // getters

    inline size_t getLength() const noexcept {
        return this->length;
    }
private:
    T *array = new T[2];

    size_t length   = 0;
    size_t capacity = 2;

    void resize() noexcept {
        this->capacity *= 2;

        T *array = new T[this->capacity];

        for (size_t i = 0; i < this->length; i++)
            array[i] = this->array[i];

        delete this->array;
        this->array = array;
    }
};
