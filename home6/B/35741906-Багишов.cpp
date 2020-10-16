#include <cstddef>
#include <utility>

template <typename T>
class UniquePtr {
    T* mPtr;

public:
    UniquePtr() noexcept : mPtr(nullptr) {
    }

    UniquePtr(T* ptr) noexcept : mPtr(ptr) {
    }

    UniquePtr(UniquePtr const&) = delete;

    UniquePtr(UniquePtr&& tmp) noexcept : mPtr(std::exchange(tmp.mPtr, nullptr)) {
    }

    UniquePtr& operator=(std::nullptr_t null) noexcept {
        delete mPtr;
        mPtr = nullptr;
        return *this;
    }

    UniquePtr& operator=(UniquePtr const&) = delete;

    UniquePtr& operator=(UniquePtr&& tmp) noexcept {
        std::swap(mPtr, tmp.mPtr);
        return *this;
    }

    T& operator*() const noexcept {
        return *mPtr;
    }

    T* operator->() const noexcept {
        return mPtr;
    }

    T* get() const noexcept {
        return mPtr;
    }

    T* release() noexcept {
        return std::exchange(mPtr, nullptr);
    }

    void reset(T* ptr) noexcept {
        *this = std::move(UniquePtr(ptr));
    }

    void swap(UniquePtr& that) noexcept {
        std::swap(mPtr, that.mPtr);
    }

    explicit operator bool() const noexcept {
        return mPtr != nullptr;
    }

    ~UniquePtr() {
        delete mPtr;
    }
};