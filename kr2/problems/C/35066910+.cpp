#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
private:
    std::vector<T> mHead, mTail;

public:
    Deque() {
    }

    bool Empty() const {
        return mHead.empty() && mTail.empty();
    }

    size_t Size() const {
        return mHead.size() + mTail.size();
    }

    void Clear() {
        mHead.clear();
        mTail.clear();
    }

    const T& operator[](size_t i) const {
        if (i < mHead.size()) {
            return mHead[mHead.size() - i - 1];
        }
        i -= mHead.size();
        return mTail[i];
    }

    T& operator[](size_t i) {
        return const_cast<T&>(const_cast<Deque const&>(*this)[i]);  //
    }

    const T& At(size_t i) const {
        if (i < Size()) {
            return (*this)[i];
        }
        throw std::out_of_range("Deque: index out of range [0; Size())");
    }

    T& At(size_t i) {
        return const_cast<T&>(const_cast<Deque const&>(*this).At(i));
    }

    const T& Front() const {
        if (mHead.empty()) {
            return mTail.front();
        } else {
            return mHead.back();
        }
    }

    T& Front() {
        return const_cast<T&>(const_cast<Deque const&>(*this).Front());
    }

    const T& Back() const {
        if (mTail.empty()) {
            return mHead.front();
        } else {
            return mTail.back();
        }
    }

    T& Back() {
        return const_cast<T&>(const_cast<Deque const&>(*this).Back());
    }

    void PushFront(const T& elem) {
        mHead.push_back(elem);
    }

    void PushBack(const T& elem) {
        mTail.push_back(elem);
    }
};