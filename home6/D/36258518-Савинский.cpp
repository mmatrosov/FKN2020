#include <cstddef>

class List {
    struct Leaf {
        int data;
        Leaf *left, *right;

        Leaf(int _data) : data(_data), left(nullptr), right(nullptr) {
        }
    };

    Leaf *front, *back;
    size_t sz;

public:
    struct Iterator {
        const List* list;
        Leaf* ptr;

        Iterator(const List* _list, Leaf* _ptr) : list(_list), ptr(_ptr) {
        }

        Iterator& operator++() {
            if (ptr == list->back) {
                ptr = nullptr;
            } else {
                ptr = ptr->right;
            }
            return *this;
        }

        Iterator& operator--() {
            if (ptr == nullptr) {
                ptr = list->back;
            } else {
                ptr = ptr->left;
            }
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        int& operator*() const {
            return ptr->data;
        }
    };

    List() : sz(0), front(nullptr), back(nullptr) {
    }

    size_t size() const {
        return sz;
    }

    void push_back(int val) {
        if (size() == 0) {
            front = back = new Leaf(val);
        } else {
            back->right = new Leaf(val);
            back->right->left = back;
            back = back->right;
        }
        sz += 1;
    }

    void push_front(int val) {
        if (size() == 0) {
            front = back = new Leaf(val);
        } else {
            front->left = new Leaf(val);
            front->left->right = front;
            front = front->left;
        }
        sz += 1;
    }

    void pop_back() {
        if (front == back) {
            delete back;
            front = back = nullptr;
        } else {
            back = back->left;
            delete back->right;
            back->right = nullptr;
        }
        sz -= 1;
    }

    void pop_front() {
        if (front == back) {
            delete front;
            front = back = nullptr;
        } else {
            front = front->right;
            delete front->left;
            front->left = nullptr;
        }
        sz -= 1;
    }

    void reset() {
        while (size() != 0) {
            pop_back();
        }
    }

    List& operator=(const List& other) {
        if (this == &other) {
            return *this;
        }
        reset();
        for (const auto& elem : other) {
            push_back(elem);
        }
        return *this;
    }

    Iterator begin() const {
        return Iterator(this, front);
    }

    Iterator end() const {
        return Iterator(this, nullptr);
    }

    ~List() {
        reset();
    }
};
