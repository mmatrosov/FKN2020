#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Queue {
 private:
    Container q;

 public:
    Queue() {
        q = Container();
    }

    const Container& get() const {
        return q;
    }

    const T& front() const {
        return q.front();
    }

    T& front() {
        return q.front();
    }

    void pop() {
        q.pop_front();
    }

    void push(const T& t) {
        q.push_back(t);
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }

    bool operator==(const Queue& q1) {
        return (q == q1.get());
    }

    bool operator!=(const Queue& q1) {
        return (q != q1.get());
    }
};