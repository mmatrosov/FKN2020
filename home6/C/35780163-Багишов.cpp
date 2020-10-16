#include <cstddef>
#include <memory>
#include <utility>

template <typename T, typename Del = std::default_delete<T>>
class UniquePtr {
    std::tuple<T*, Del> mItems;

public:
    UniquePtr() noexcept : mItems(nullptr, Del()) {
    }

    UniquePtr(T* ptr) noexcept : mItems(ptr, Del()) {
    }

    UniquePtr(T* ptr, Del && deleter) : mItems(ptr, deleter) {
    }

    UniquePtr(UniquePtr const&) = delete;

    UniquePtr(UniquePtr && tmp) noexcept
        : mItems(std::exchange(std::get<0>(tmp.mItems), nullptr),
                 std::move(std::get<1>(tmp.mItems))) {
    }

    UniquePtr& operator=(std::nullptr_t null) noexcept {
        reset(nullptr);
        return *this;
    }

    UniquePtr& operator=(UniquePtr const&) = delete;

    UniquePtr& operator=(UniquePtr&& tmp) noexcept {
        std::swap(mItems, tmp.mItems);
        return *this;
    }

    T& operator*() const noexcept {
        return *get();
    }

    T* operator->() const noexcept {
        return get();
    }

    T* get() const noexcept {
        return std::get<0>(mItems);
    }

    T* release() noexcept {
        return std::exchange(std::get<0>(mItems), nullptr);
    }

    void reset(T* ptr) noexcept {
        *this = std::move(UniquePtr(ptr));
    }

    void swap(UniquePtr& that) noexcept {
        std::swap(mItems, that.mItems);
    }

    explicit operator bool() const noexcept {
        return get() != nullptr;
    }

    Del& get_deleter() {
        return std::get<1>(mItems);
    }

    Del const& get_deleter() const {
        return std::get<1>(mItems);
    }

    ~UniquePtr() {
        if (*this) {
            (std::get<1>(mItems))(get());
        }
    }
};