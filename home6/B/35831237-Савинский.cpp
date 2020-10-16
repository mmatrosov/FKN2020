#include <cstddef>
#include <utility>

template <typename T>
class UniquePtr {
    T* ptr;

   public:
    UniquePtr() : ptr(nullptr) {
    }

    UniquePtr(T* _ptr) : ptr(_ptr) {
    }

    UniquePtr(UniquePtr& other) = delete;

    UniquePtr& operator=(UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    UniquePtr& operator=(const std::nullptr_t np) noexcept {
        this->~UniquePtr();
        ptr = np;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        std::swap(ptr, other.ptr);
    }

    ~UniquePtr() noexcept {
        if (ptr != nullptr) {
            delete ptr;
        }
        ptr = nullptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T* release() noexcept {
        T* res = ptr;
        ptr = nullptr;
        return res;
    }

    void reset(T* _ptr) {
        this->~UniquePtr();
        ptr = _ptr;
    }

    void swap(UniquePtr& other) noexcept {
        std::swap(ptr, other.ptr);
    }

    T* get() const noexcept {
        return ptr;
    }

    explicit operator bool() const noexcept {
        return ptr != nullptr;
    }
};
