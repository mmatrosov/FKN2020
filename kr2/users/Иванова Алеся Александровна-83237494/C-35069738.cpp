#include <cstddef>
#include <vector>
#include <stdexcept>

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
        head.resize(0);
        tail.resize(0);
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

    const T& At(size_t i) const {  // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size())
            throw std::out_of_range("");
        if (i < head.size())
            return head[head.size() - i - 1];
        return tail[i - head.size()];
    }

    T& At(size_t i) {  // throws std::out_of_range on incorrect index
        if (i >= head.size() + tail.size())
            throw std::out_of_range("");
        if (i < head.size())
            return head[head.size() - i - 1];
        return tail[i - head.size()];
    }

    const T& Front() const {
        if (head.empty())
            return tail[0];
        return head.back();
    }

    T& Front() {
        if (head.empty())
            return tail[0];
        return head.back();
    }

    const T& Back() const {
        if (tail.empty())
            return head[0];
        return tail.back();
    }

    T& Back() {
        if (tail.empty())
            return head[0];
        return tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};