#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, int> data;

public:
    void increaseNumberOf(int id) {
        data[id]++;
    }

    void decreaseNumberOf(int id) {
        data[id]--;
        if (data[id] < 0)
            data[id] = 0;
    }

    size_t getNumberOf(int id) const {
        if (data.find(id) == data.end()) return 0;
        return data.at(id);
    }
};