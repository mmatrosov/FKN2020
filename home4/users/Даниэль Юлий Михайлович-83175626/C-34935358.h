#include <deque>

template <typename T, typename Container = std::deque<T>>

class Queue {
   private:
    Container cont;

   public:
    Queue() {
    }

    const T front() const {
        return cont.front();
    }

    T& front() {
        return cont.front();
    }

    void pop() {
        cont.pop_front();
    }

    void push(const T& elem) {
        cont.push_back(elem);
    }

    int size() const {
        return cont.size();
    }

    bool empty() const {
        return size() == 0;
    }

    bool operator==(const Queue& other) const {
        return cont == other.cont;
    }

    bool operator!=(const Queue& other) const {
        return cont != other.cont;
    }
};