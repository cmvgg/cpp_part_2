#include <iostream>
#include <cstdlib>
#include <exception>
#include <stdexcept>

template <typename T>
class Array {
private:
    T *element;
    unsigned int length;

public:
    Array() : element(new T[0]), length(0) {}

    explicit Array(unsigned int s) : element(new T[s]), length(s) {}

    ~Array() {
        delete[] element;
    }

    Array(const Array &other) : element(new T[other.length]), length(other.length) {
        if (this != &other) {
            for (unsigned int i = 0; i < length; ++i) {
                element[i] = other.element[i];
            }
        }
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] element;
            length = other.length;
            element = new T[length];
            for (unsigned int i = 0; i < length; ++i) {
                element[i] = other.element[i];
            }
        }
        return *this;
    }

    T &operator[](size_t p) {
        if (p >= length)
            throw std::out_of_range("out of range");
        return element[p];
    }

    unsigned int size() const {
        return length;
    }
};
