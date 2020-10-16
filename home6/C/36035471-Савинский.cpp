#include <cstddef>
#include <memory>
#include <utility>

template <typename T, typename Deleter = std::default_delete<T>>
class UniquePtr {
    std::tuple<T*, Deleter> data;

   public:
    UniquePtr() : data({nullptr, Deleter()}) {
    }

    UniquePtr(T* _ptr) : data({_ptr, Deleter()}) {
    }

    UniquePtr(T* _ptr, const Deleter& _deleter) : data({_ptr, _deleter}) {
    }

    UniquePtr(UniquePtr& other) = delete;

    UniquePtr& operator=(UniquePtr& other) = delete;

    UniquePtr(UniquePtr&& other) noexcept {
        std::get<0>(data) = std::get<0>(other.data);
        std::get<0>(other.data) = nullptr;
    }

    UniquePtr& operator=(const std::nullptr_t np) noexcept {
        this->~UniquePtr();
        std::get<0>(data) = np;
        return *this;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        std::swap(std::get<0>(data), std::get<0>(other.data));
    }

    ~UniquePtr() noexcept {
        if (*this) {
            std::get<1>(data)(std::get<0>(data));
        }
        std::get<0>(data) = nullptr;
    }

    T& operator*() const {
        return *std::get<0>(data);
    }

    T* operator->() const {
        return std::get<0>(data);
    }

    T* release() noexcept {
        T* res = std::get<0>(data);
        std::get<0>(data) = nullptr;
        return res;
    }

    void reset(T* _ptr) {
        this->~UniquePtr();
        std::get<0>(data) = _ptr;
    }

    void swap(UniquePtr& other) noexcept {
        std::swap(std::get<0>(data), std::get<0>(other.data));
    }

    T* get() const noexcept {
        return std::get<0>(data);
    }

    explicit operator bool() const noexcept {
        return std::get<0>(data) != nullptr;
    }

    Deleter& get_deleter() {
        return std::get<1>(data);
    }

    Deleter get_deleter() const {
        return std::get<1>(data);
    }
};
