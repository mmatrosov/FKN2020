#include <cstddef>
#include <stdexcept>
#include <string>
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
        if (i < head.size()) {
            return head[head.size() - 1 - i];
        } else {
            return tail[i - head.size()];
        }
    }

    T& operator[](size_t i) {
        if (i < head.size()) {
            return head[head.size() - 1 - i];
        } else {
            return tail[i - head.size()];
        }
    }

    const T& At(size_t i) const {  // throws std::out_of_range on incorrect index
        if (i > Size())
            throw std::out_of_range(std::to_string(i));
        if (i < head.size()) {
            return head[head.size() - 1 - i];
        } else {
            return tail[i - head.size()];
        }
    }

    T& At(size_t i) {  // throws std::out_of_range on incorrect index
        if (i > Size())
            throw std::out_of_range(std::to_string(i));
        if (i < head.size())
            return head[head.size() - 1 - i];
        else
            return tail[i - head.size()];
    }

    const T& Front() const {
        if (!head.empty())
            return head.back();
        else
            return tail[0];
    }

    T& Front() {
        if (!head.empty())
            return head.back();
        else
            return tail[0];
    }

    const T& Back() const {
        if (!tail.empty())
            return tail.back();
        else
            return head[0];
    }

    T& Back() {
        if (!tail.empty())
            return tail.back();
        else
            return head[0];
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};
