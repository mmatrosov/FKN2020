#include <cstddef>
#include <utility>

template <typename T>
class UniquePtr {
    T* ptr = nullptr;

public:
    UniquePtr() {
    }

    UniquePtr(T* ptr0) {
        ptr = ptr0;
    }

    UniquePtr(UniquePtr&& other) {
        (*this) = std::move(other);
    }

    UniquePtr& operator=(UniquePtr&& other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return (*this);
    }

    UniquePtr& operator=(std::nullptr_t) {
        delete ptr;
        ptr = nullptr;
        return (*this);
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* release() {
        T* copy = ptr;
        ptr = nullptr;
        return copy;
    }

    void reset(T* ptr0) {
        delete ptr;
        ptr = ptr0;
    }

    void swap(UniquePtr& other) {
        std::swap(ptr, other.ptr);
    }

    T* get() const {
        return ptr;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }

    ~UniquePtr() {
        delete ptr;
    }
};