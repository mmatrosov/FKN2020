#include <deque>
#include <iostream>
#include <string>

class Vim {
   private:
    int condition;
    int pos;
    // 0 - viewing
    // 1 - inserting
    std::deque<char> head;
    std::deque<char> tail;

   public:
    Vim() {
        condition = 0;
        pos = 0;
        head = {};
        tail = {};
    }
    void print() {
        for (auto i : head) {
            std::cout << i;
        }
        for (auto i : tail) {
            std::cout << i;
        }
    }
    void push(char x) {
        head.push_back(x);
    }

    int process_next(char cur) {
        if (cur == '<') {
            pos += 4;
            condition = 0;
        } else {
            if (condition == 1) {
                push(cur);
            } else {
                if (cur == 'l') {
                    if (tail.size() != 0) {
                        char x = tail.front();
                        tail.pop_front();
                        head.push_back(x);
                    }
                } else if (cur == 'h') {
                    if (head.size() != 0) {
                        char x = head.back();
                        head.pop_back();
                        tail.push_front(x);
                    }
                } else if (cur == 'i') {
                    condition = 1;
                }
            }
        }
        pos += 1;
        return pos;
    }
};

int main() {
    std::string data;
    std::cin >> data;
    int size = data.size();
    int i = 0;
    Vim vim;
    while (i < size) {
        i = vim.process_next(data[i]);
    }
    vim.print();
    return 0;
}
