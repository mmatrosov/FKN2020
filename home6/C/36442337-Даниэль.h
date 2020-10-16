#include <cstddef>
#include <iostream>
#include <memory>
#include <tuple>
#include <utility>

template <typename T, class Deleter = std::default_delete<T>>
class UniquePtr {
    std::tuple<T*, Deleter> data;

public:
    UniquePtr() {
        std::get<1>(data) = Deleter();
    }

    UniquePtr(T* ptr0) {
        data = {ptr0, Deleter()};
    }

    UniquePtr(T* ptr0, Deleter deleter0) {
        data = {ptr0, deleter0};
    }

    UniquePtr(UniquePtr&& other) {
        (*this) = std::move(other);
    }

    UniquePtr& operator=(UniquePtr&& other) {
        std::swap(data, other.data);
        return (*this);
    }

    UniquePtr& operator=(std::nullptr_t) {
        auto& [ptr, deleter] = data;
        deleter(ptr);
        ptr = nullptr;
        return (*this);
    }

    T& operator*() const {
        return *std::get<0>(data);
    }

    T* operator->() const {
        return std::get<0>(data);
    }

    T* release() {
        T* copy = std::get<0>(data);
        std::get<0>(data) = nullptr;
        return copy;
    }

    void reset(T* ptr0) {
        auto& [ptr, deleter] = data;
        deleter(ptr);
        ptr = ptr0;
    }

    void swap(UniquePtr& other) {
        std::swap(data, other.data);
    }

    T* get() const {
        return std::get<0>(data);
    }

    Deleter& get_deleter() {
        return std::get<1>(data);
    }

    const Deleter& get_deleter() const {
        return std::get<1>(data);
    }

    explicit operator bool() const {
        return std::get<0>(data) != nullptr;
    }

    ~UniquePtr() {
        auto& [ptr, deleter] = data;
        deleter(ptr);
    }
};