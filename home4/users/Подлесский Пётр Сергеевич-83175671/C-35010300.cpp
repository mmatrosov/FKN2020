#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
   private:
    Container data;

   public:
    size_t size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }

    T front() const {
        return data.front();
    }

    T& front() {
        return data.front();
    }

    void pop() {
        data.pop_front();
    }

    void push(const T& value) {
        data.push_back(value);
        int& i = 0;
    }

    void push(T&& value) {
        data.push_back(value);
    }

    friend bool operator==(const Queue<T>& q1, const Queue<T>& q2) {
        return q1.data == q2.data;
    }

    friend bool operator!=(const Queue<T>& q1, const Queue<T>& q2) {
        return q1.data != q2.data;
    }
};
