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
        auto it = data.find(id);
        if (it->second <= 0)
            data.erase(it);
    }

    size_t getNumberOf(int id) const {
        auto it = data.find(id);
        if (it == data.end())
            return 0;
        else
            return it->second;
    }
};