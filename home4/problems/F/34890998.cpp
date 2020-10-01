#include <string>
#include <iostream>

class Vim {
 private:
    std::string text;
    bool flag;
    int id;

 public:
    Vim() {
        text = "";
        flag = 0;
        id = 0;
    }

    bool isIns() const {
        return flag;
    }

    void MoveRight() {
        if (id < text.size()) {
            ++id;
        }
    }

    void MoveLeft() {
        if (id > 0) {
            --id;
        }
    }

    void ToInsert() {
        flag = 1;
    }

    void ToWatch() {
        flag = 0;
    }

    void update(const char& c) {
        if (flag) {
            text.insert(text.begin() + id, c);
            ++id;
        }
    }

    void print() {
        std::cout << text;
    }
};

int main() {
    Vim v = Vim();
    std::string query;
    std::cin >> query;
    for (int i = 0; i < query.size(); ++i) {
        char c = query[i];
        if (c == '<') {
            v.ToWatch();
            i += 3;
        }
        if (c == 'l' && !v.isIns()) {
            v.MoveRight();
        } else if (c == 'h' && !v.isIns()) {
            v.MoveLeft();
        } else if (c == 'i' && !v.isIns()) {
            v.ToInsert();
        } else {
            v.update(c);
        }
    }
    v.print();
    return 0;
}