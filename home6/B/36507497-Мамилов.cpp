#include <memory>
#include <cstddef>

template<typename T>
class UniquePtr {
private:
    T* ptr = nullptr;

public:
    UniquePtr() noexcept {}

    UniquePtr(T* newPtr) noexcept {
        this->ptr = newPtr;
        newPtr = nullptr;
    }

    T* release() noexcept {
        T* newPtr = ptr;
        ptr = nullptr;
        return newPtr;
    }

    void reset(T* newPtr) noexcept {
        *this = nullptr;
        this->ptr = newPtr;
    }

    void swap(UniquePtr& other) noexcept {
        T* tmp = other.release();
        other.ptr = this->release();
        this->ptr = tmp;
    }

    UniquePtr(UniquePtr&& other) noexcept {
        this->ptr = other.release();
    }

    UniquePtr& operator=(std::nullptr_t) {
        if (this->ptr)
            delete this->ptr;
        this->ptr = nullptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        *this = nullptr;
        this->reset(other.release());
        return *this;
    }

    T* get() const {
        return ptr;
    }

    T* operator->() const {
        return get();
    }

    T& operator*() const noexcept {
        return *ptr;
    }

    explicit operator bool() const {
        return (ptr != nullptr);
    }

    ~UniquePtr() noexcept {
        if (ptr)
            delete ptr;
    }
};