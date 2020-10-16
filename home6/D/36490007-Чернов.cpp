#include <cstddef>

class List {
private:
    class Node {
    public:
        Node* next = nullptr;
        Node* prev = nullptr;
        int value;

        Node(int x) : value(x) {
        }
    };

    class Iterator {
    public:
        Node* node;

        Iterator() : node(nullptr) {
        }

        Iterator(Node* _node) : node(_node) {
        }

        Iterator(const Iterator& other) : node(other.node) {
        }

        bool operator==(const Iterator& other) {
            return node == other.node;
        }

        bool operator!=(const Iterator& other) {
            return node != other.node;
        }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }

        Iterator& operator--() {
            node = node->prev;
            return *this;
        }

        int operator*() {
            return node->value;
        }
    };

    Node* head;
    Node* tail;
    size_t elems;
    Iterator begin_iterator;
    Iterator end_iterator;

public:
    List() {
        elems = 0;
        head = tail = new Node(0);
        begin_iterator = Iterator(head);
        end_iterator = Iterator(tail);
    }

    Iterator begin() const {
        return begin_iterator;
    }

    Iterator end() const {
        return end_iterator;
    }

    size_t size() const {
        return elems;
    }

    void push_front(int x) {
        Node* curNode = new Node(x);

        curNode->next = head;
        head->prev = curNode;
        head = curNode;

        begin_iterator = Iterator(head);

        ++elems;
    }

    void push_back(int x) {
        if (head == tail) {
            push_front(x);
            return;
        }

        Node* curNode = new Node(x);

        curNode->next = tail;
        curNode->prev = tail->prev;
        tail->prev->next = curNode;
        tail->prev = curNode;

        end_iterator = Iterator(tail);

        ++elems;
    }

    void pop_front() {
        Node* del = head;

        head = head->next;
        head->prev = nullptr;

        begin_iterator = Iterator(head);

        --elems;

        delete del;
    }

    void pop_back() {
        Node* del = tail->prev;

        if (del->prev == nullptr) {
            pop_front();
            return;
        }

        del->prev->next = tail;
        tail->prev = del->prev;

        --elems;

        delete del;
    }

    List& operator=(const List& other) {
        Node* curNode1 = head;
        Node* curNode2 = other.head;
        for (size_t i = 0; i < elems && i < other.elems; ++i, ++curNode1, ++curNode2) {
            curNode1->value = curNode2->value;
        }
        if (elems > other.elems) {
            for (size_t i = 0; i < elems - other.elems; ++i) {
                pop_back();
            }
        } else {
            if (elems < other.elems) {
                for (size_t i = elems; i < other.elems; ++i, ++curNode2) {
                    push_back(curNode2->value);
                }
            }
        }
        return *this;
    }

    ~List() {
        Node* del = head;
        Node* curNode = head;
        while (curNode != tail) {
            curNode = curNode->next;
            delete del;
            del = curNode;
        }
        delete del;
    }
};