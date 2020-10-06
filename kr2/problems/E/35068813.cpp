#include <unordered_map>

class Counter {
private:
    std::unordered_map <int, size_t> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        if (data[id] == 0) {
            return;
        }
        --data[id];
    }

    size_t getNumberOf(int id) {
        if (data.find(id) == data.end()) {
            return 0;
        }
        return data[id];
    }
};