#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, int> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        if (data[id])  //
            --data[id];
    }

    size_t getNumberOf(int id) const {
        auto it = data.find(id);
        if (it == data.end())
            return 0;
        return (*it).second;
    }
};

/*#include <iostream>
#include <string>
int main() {
    Counter a;
    while (true) {
        std::string s;
        std::cin >> s;
        if (s == "increase") {
            int id;
            std::cin >> id;
            a.increaseNumberOf(id);
        }
        if (s == "decrease") {
            int id;
            std::cin >> id;
            a.decreaseNumberOf(id);
        }
        if (s == "get") {

        }
    }
}*/
