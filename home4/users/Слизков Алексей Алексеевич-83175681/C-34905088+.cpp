#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
    Container contents;

   public:
    Queue() {
    }

    const T& front() const {
        return contents.front();
    }
    T& front() {
        return contents.front();
    }

    void pop() {
        contents.pop_front();
    }
    void push(const T& elem) {
        contents.push_back(elem);
    }

    size_t size() const {
        return contents.size();
    }
    bool empty() const {
        return contents.size() == 0;
    }

    template <typename _T, typename _Container>
    bool operator==(const Queue<_T, _Container>& another) const {
        return size() == another.size() && contents == another.contents;
    }

    template <typename _T, typename _Container>
    bool operator!=(const Queue<_T, _Container>& another) const {
        return size() != another.size() || contents != another.contents;
    }
};

/*#include <iostream>
#include <string>

int main() {
    Queue<int> q;
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "pop")
            q.pop();
        else if (command == "push") {
            int x;
            std::cin >> x;
            q.push(x);
        }
        else if (command == "size") {
            std::cout << q.size() << '\n';
        }
        else if (command == "empty") {
            std::cout << q.empty() << '\n';
        }
        else if (command == "front") {
            std::cout << q.front() << '\n';
        }
        else if (command == "change_front") {
            int x;
            std::cin >> x;
            q.front() = x;
        }
    }
}*/
