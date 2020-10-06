#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    Deque() {}

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
            return head[head.size() - 1 - i];
        return tail[i - head.size()];
    }

    T& operator[] (size_t i) {
        if (i < head.size())
            return head[head.size() - 1 - i];
        return tail[i - head.size()];
    }

    const T& At(size_t i) const {
        if (i >= this->Size())
            throw std::out_of_range("Incorrect index");
        return (*this)[i];
    }  // throws std::out_of_range on incorrect index

    T& At(size_t i) {
        if (i >= this->Size())
            throw std::out_of_range("Incorrect index");
        return (*this)[i];
    }  // throws std::out_of_range on incorrect index

    const T& Front() const {
        if (!head.empty())
            return head.back();
        return tail.front();
    }

    T& Front() {
        if (!head.empty())
            return head.back();
        return tail.front();
    }

    const T& Back() const {
        if (!tail.empty())
            return tail.back();
        return head.front();
    }

    T& Back() {
        if (!tail.empty())
            return tail.back();
        return head.front();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};