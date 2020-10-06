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
        if (i < head.size())
            return head[head.size() - 1 - i];
        return tail[i - head.size()];
    }

    T& operator[](size_t i) {
        if (i < head.size())
            return head[head.size() - 1 - i];
        return tail[i - head.size()];
    }

    const T& At(size_t i) const {  // throws std::out_of_range on incorrect index
        if (i < head.size())
            return head[head.size() - 1 - i];
        if (i < head.size() + tail.size())
            return tail[i - head.size()];
        throw std::out_of_range("");
    }

    T& At(size_t i) {  // throws std::out_of_range on incorrect index
        if (i < head.size())
            return head[head.size() - 1 - i];
        if (i < head.size() + tail.size())
            return tail[i - head.size()];
        throw std::out_of_range("");
    }

    const T& Front() const {
        return head.size() ? head.back() : tail.front();
    }

    T& Front() {
        return head.size() ? head.back() : tail.front();
    }

    const T& Back() const {
        return tail.size() ? tail.back() : head.front();
    }

    T& Back() {
        return tail.size() ? tail.back() : head.front();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};
