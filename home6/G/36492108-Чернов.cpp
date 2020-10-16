#include <cstddef>
#include <utility>

class Vector {
private:
    class Memory {
    private:
        int* data;

    public:
        Memory() {
            data = nullptr;
        }

        Memory(size_t n) {
            data = new int[n];
        }

        int& operator[](size_t i) {
            return *(data + i);
        }

        const int& operator[](size_t i) const {
            return *(data + i);
        }

        void swap(Memory& other) {
            std::swap(data, other.data);
        }

        ~Memory() {
            delete[] data;
        }
    };

    Memory data;
    size_t elems;
    size_t capacity;

public:
    Vector() {
        elems = 0;
        capacity = 0;
    }

    Vector(const Vector& other) {
        Memory data2(other.elems);
        data.swap(data2);
        for (size_t i = 0; i < other.elems; ++i) {
            data[i] = other.data[i];
        }
        elems = other.elems;
        capacity = elems;
    }

    void swap(Vector& other) {
        data.swap(other.data);
        std::swap(elems, other.elems);
        std::swap(capacity, other.capacity);
    }

    Vector& operator=(const Vector& other) {
        Vector tmp(other);
        (*this).swap(tmp);
        return *this;
    }

    size_t size() const {
        return elems;
    }

    int operator[](size_t i) {
        return data[i];
    }

    void push_back(int x) {
        if (elems < capacity) {
            data[elems] = x;
            ++elems;
        } else {
            Memory data2(elems == 0 ? 1 : 2 * elems);
            for (size_t i = 0; i < elems; ++i) {
                data2[i] = data[i];
            }
            data.swap(data2);
            data[elems] = x;
            capacity = 2 * elems;
            ++elems;
        }
    }

    void pop_back() {
        --elems;
    }
};