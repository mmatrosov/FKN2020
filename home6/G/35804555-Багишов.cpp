#include <memory>
#include <utility>

template <typename T>
class TplVector {
    T* mBuf;
    size_t mCapacity;
    size_t mLen;

    T* raw_get(size_t pos) const {
        return mBuf + pos;
    }

    void drop_objects(size_t keep_count) {
        for (size_t i = keep_count; i < mLen; ++i) {
            (mBuf + i)->~T();
        }
    }

    void move_objects_to(T* new_buf) {
        for (size_t i = 0; i < mLen; ++i) {
            new (new_buf + i) T(std::move(mBuf[i]));
        }
    }

    void drop_storage_and_objects() {
        if (mCapacity != 0) {
            drop_objects(0);
            std::allocator<T> alloc;
            alloc.deallocate(mBuf, mCapacity);
            mBuf = nullptr;
        }
    }

    void grow_to(size_t new_capacity) {
        std::allocator<T> alloc;
        T* new_buf = alloc.allocate(new_capacity);
        move_objects_to(new_buf);
        drop_storage_and_objects();
        mCapacity = new_capacity;
        mBuf = new_buf;
    }

    void grow_with_default_policy() {
        size_t new_capacity = (mCapacity == 0 ? 1 : mCapacity * 2);
        grow_to(new_capacity);
    }

    template <typename F>
    void resize_with(size_t new_size, F&& func) {
        if (mLen >= new_size) {
            mLen = new_size;
            drop_objects(new_size);
            return;
        }
        if (new_size > mCapacity) {
            grow_to(new_size);
        }
        for (size_t pos = mLen; pos < new_size; ++pos) {
            emplace_back(func());
        }
    }

public:
    TplVector() : mBuf(nullptr), mCapacity(0), mLen(0) {
    }

    explicit TplVector(T const& value) : TplVector() {
        push_back(value);
    }

    explicit TplVector(T&& value) : TplVector() {
        push_back(std::move(value));
    }

    TplVector(size_t size) : TplVector() {
        resize(size);
    }

    TplVector(size_t size, T fill) : TplVector() {
        resize(size, fill);
    }

    TplVector(TplVector&& tmp)
        : mBuf(std::exchange(tmp.mBuf, nullptr)),
          mCapacity(std::exchange(tmp.mCapacity, 0)),
          mLen(std::exchange(tmp.mLen, 0)) {
    }

    TplVector(TplVector const& that) : TplVector() {
        *this = that;
    }

    TplVector& operator=(TplVector&& tmp) {
        std::swap(mBuf, tmp.mBuf);
        std::swap(mLen, tmp.mLen);
        std::swap(mCapacity, tmp.mCapacity);
        return *this;
    }

    TplVector& operator=(TplVector const& that) {
        clear();
        reserve(that.size());
        for (size_t i = 0; i < that.size(); ++i) {
            emplace_back(that[i]);
        }
        return *this;
    }

    size_t capacity() const {
        return mCapacity;
    }

    size_t size() const {
        return mLen;
    }

    void clear() noexcept {
        mLen = 0;
        drop_objects(0);
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > mCapacity) {
            grow_to(new_capacity);
        }
    }

    void resize(size_t new_size, T const& fill) {
        resize_with(new_size, [&]() { return fill; });
    }

    void resize(size_t new_size) {
        resize_with(new_size, [&]() { return T(); });
    }

    template <typename... Args>
    void emplace_back(Args&&... args) {
        if (mLen == mCapacity) {
            grow_with_default_policy();
        }

        new (raw_get(mLen)) T(std::forward<Args>(args)...);
        ++mLen;
    }

    void push_back(T&& tmp) {
        emplace_back(std::move(tmp));
    }

    void push_back(T const& val) {
        emplace_back(val);
    }

    void pop_back() {
        drop_objects(mLen - 1);
        mLen--;
    }

    T const& operator[](size_t pos) const {
        return *raw_get(pos);
    }

    T& operator[](size_t pos) {
        return *raw_get(pos);
    }

    T const* begin() const {
        return mBuf;
    }

    T* begin() {
        return mBuf;
    }

    T const* end() const {
        return mBuf + mLen;
    }

    T* end() {
        return mBuf + mLen;
    }

    ~TplVector() {
        drop_storage_and_objects();
    }
};

using Vector = TplVector<int>;