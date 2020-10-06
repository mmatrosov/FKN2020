#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, size_t> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        if (data.count(id) != 0 && data[id] != 0)
            --data[id];
    }

    size_t getNumberOf(int id) const {
        auto it = data.find(id);
        if (it == data.end()) {
            return 0;
        }
        return (*it).second;
    }
};