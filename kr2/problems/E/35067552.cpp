#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, int> data;

public:
    void increaseNumberOf(int id) {
        data[id] += 1;
    }

    void decreaseNumberOf(int id) {
        data[id] = std::max(data[id] - 1, 0);
    }

    size_t getNumberOf(int id) const {
        auto it = data.find(id);
        return (it == data.end() ? 0 : it->second);
    }
};
