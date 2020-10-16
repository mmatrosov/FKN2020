#include <memory>
#include <stdexcept>
#include <utility>

class BadOptionalAccess : public std::exception {
    char const* what() const noexcept override {
        return "tried to unwrap empty Optional";
    }
};

template <typename T>
class Optional {
    alignas(T) unsigned char mData[sizeof(T)];
    bool mHasValue;

    template <typename... Args>
    void construct(Args&&... args) {
        new (mData) T(std::forward<Args>(args)...);
        mHasValue = true;
    }

    T const* get_object_ptr() const {
        return reinterpret_cast<T const*>(&mData);
    }

    T* get_object_ptr() {
        return reinterpret_cast<T*>(&mData);
    }

public:
    Optional(T const& value) {
        construct(value);
    }

    Optional(T && value) {
        construct(std::move(value));
    }

    Optional() : mHasValue(false) {
    }

    Optional(Optional&& tmp) : mHasValue(false) {
        if (tmp.mHasValue) {
            construct(std::move(*tmp));
            tmp.reset();
        }
    }

    Optional(Optional const& that) : mHasValue(false) {
        if (that.mHasValue) {
            construct(*that);
        }
    }

    Optional& operator=(Optional&& tmp) {
        if (!tmp.mHasValue) {
            reset();
            return *this;
        }

        if (mHasValue) {
            std::swap(**this, *tmp);
        } else {
            construct(std::move(*tmp));
            tmp.reset();
        }
        return *this;
    }

    Optional& operator=(T&& tmp) {
        if (mHasValue) {
            **this = std::move(tmp);
        } else {
            construct(std::move(tmp));
        }
        return *this;
    }

    Optional& operator=(Optional const& that) {
        if (!that.mHasValue) {
            reset();
            return *this;
        }

        if (mHasValue) {
            *get_object_ptr() = *that;
        } else {
            construct(*that);
        }
        return *this;
    }

    Optional& operator=(T const& val) {
        if (mHasValue) {
            **this = val;
        } else {
            construct(val);
        }
        return *this;
    }

    bool has_value() const noexcept {
        return mHasValue;
    }

    explicit operator bool() const noexcept {
        return has_value();
    }

    T const* operator->() const noexcept {
        return get_object_ptr();
    }

    T* operator->() noexcept {
        return get_object_ptr();
    }

    T const& operator*() const noexcept {
        return *get_object_ptr();
    }

    T& operator*() noexcept {
        return *get_object_ptr();
    }

    T const& value() const {
        if (has_value()) {
            return *get_object_ptr();
        }
        throw BadOptionalAccess{};
    }

    T& value() {
        return const_cast<T&>(static_cast<Optional const&>(*this).value());
    }

    void reset() {
        if (!mHasValue) {
            return;
        }
        mHasValue = false;
        get_object_ptr()->~T();
    }

    ~Optional() {
        reset();
    }
};
