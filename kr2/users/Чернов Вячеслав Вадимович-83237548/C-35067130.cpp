#include <cstddef>
#include <stdexcept>
#include <vector>

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

    const T& operator[](size_t i) const {
        if (i >= head.size()) {
            return tail[i - head.size()];
        }
        return head[head.size() - i - 1];
    }

    T& operator[](size_t i) {
        if (i >= head.size()) {
            return tail[i - head.size()];
        }
        return head[head.size() - i - 1];
    }

    const T& At(size_t i) const {
        if (i >= Size()) {
            throw std::out_of_range("Incorrect index");
        }
        return (*this)[i];
    }

    T& At(size_t i) {
        if (i >= Size()) {
            throw std::out_of_range("Incorrect index");
        }
        return (*this)[i];
    }

    const T& Front() const {
        if (head.empty()) {
            return tail[0];
        }
        return head.back();
    }

    T& Front() {
        if (head.empty()) {
            return tail[0];
        }
        return head.back();
    }

    const T& Back() const {
        if (tail.empty()) {
            return head[0];
        }
        return tail.back();
    }

    T& Back() {
        if (tail.empty()) {
            return head[0];
        }
        return tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};