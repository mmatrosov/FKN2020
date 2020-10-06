#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, int> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        if (!data.count(id)) {
            return;
        }
        if (--data[id] == 0) {
            data.erase(id);
        }
    }

    size_t getNumberOf(int id) const {
        if (data.count(id)) {
            return data.at(id);
        } else {
            return 0;
        }
    }
};