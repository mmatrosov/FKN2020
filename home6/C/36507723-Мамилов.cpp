#include <cstddef>
#include <memory>
#include <tuple>

template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr {
private:
    std::tuple<T*, Deleter> args;

    T*& ptr() {
        return std::get<0>(args);
    }

    T* ptr() const {
        return std::get<0>(args);
    }

    Deleter& get_deleter() {
        return std::get<1>(args);
    }

    Deleter& get_deleter() const {
        return std::get<1>(args);
    }

public:
    UniquePtr() noexcept {
        ptr() = nullptr;
    }

    UniquePtr(T* newPtr) noexcept {
        this->ptr() = newPtr;
    }

    UniquePtr(T* newPtr, Deleter D) {
        this->ptr() = newPtr;
        get_deleter() = D;
    }

    T* release() noexcept {
        T* newPtr = ptr();
        this->ptr() = nullptr;
        return newPtr;
    }

    void reset(T* newPtr) noexcept {
        *this = nullptr;
        this->ptr() = newPtr;
    }

    void swap(UniquePtr& other) noexcept {
        T* tmp = other.release();
        other.ptr() = this->release();
        this->ptr() = tmp;
    }

    UniquePtr(UniquePtr&& other) noexcept {
        this->ptr() = other.release();
    }

    UniquePtr& operator=(std::nullptr_t) {
        if (this->ptr())
            get_deleter()(this->ptr());
        this->ptr() = nullptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        *this = nullptr;
        this->reset(other.release());
        return *this;
    }

    T* get() const {
        return ptr();
    }

    T* operator->() const {
        return get();
    }

    T& operator*() const noexcept {
        return *ptr();
    }

    explicit operator bool() const {
        return (ptr() != nullptr);
    }

    ~UniquePtr() noexcept {
        if (ptr())
            get_deleter()(ptr());
    }
};