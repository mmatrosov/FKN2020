#include <cstddef>
#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    Deque() {
    }

    bool Empty() const {
        return head.empty() && tail.empty();
    }

    size_t Size() const {
        return head.size() + tail.size();
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator[] (size_t i) const {
        if (i < head.size())
            return head[head.size() - i - 1];
        return tail[i - head.size()];
    }

    T& operator[] (size_t i) {
        if (i < head.size())
            return head[head.size() - i - 1];
        return tail[i - head.size()];
    }

    const T& At(size_t i) const {
        if (i >= Size()) throw(std::out_of_range("Index is too big"));
        return (*this)[i];
    }

    T& At(size_t i) {
        if (i >= Size()) throw(std::out_of_range("Index is too big"));
        return (*this)[i];
    }

    const T& Front() const {
        return (*this)[0];
    }

    T& Front() {
        return (*this)[0];
    }

    const T& Back() const {
        return (*this)[Size() - 1];
    }

    T& Back() {
        return (*this)[Size() - 1];
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};