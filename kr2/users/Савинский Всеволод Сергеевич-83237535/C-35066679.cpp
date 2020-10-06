#include <stdexcept>
#include <cstddef>
#include <vector>

template<typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    Deque() : head(), tail() {
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

    const T &operator[](size_t i) const {
        if (head.size() <= i) {
            return tail[i - head.size()];
        }
        return head[head.size() - i - 1];
    }

    T &operator[](size_t i) {
        if (head.size() <= i) {
            return tail[i - head.size()];
        }
        return head[head.size() - i - 1];
    }

    const T &At(size_t i) const {  // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size()) {
            throw std::out_of_range("deque index out of range");
        }
        return (*this)[i];
    }

    T &At(size_t i) {  // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size()) {
            throw std::out_of_range("deque index out of range");
        }
        return (*this)[i];
    }

    const T &Front() const {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    T &Front() {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    const T &Back() const {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    T &Back() {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    void PushFront(const T &elem) {
        head.emplace_back(elem);
    }

    void PushBack(const T &elem) {
        tail.emplace_back(elem);
    }
};
