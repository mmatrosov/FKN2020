#include <unordered_map>

class Counter {
private:
    std::unordered_map<int, int> data;

public:
    void increaseNumberOf(int id) {
        ++data[id];
    }

    void decreaseNumberOf(int id) {
        auto pt = data.find(id);
        if (pt != data.end()) {
            --(*pt).second;
            if (!(*pt).second)
                data.erase(pt);
        }
    }

    size_t getNumberOf(int id) const {
        auto pt = data.find(id);
        if (pt != data.end())
            return (*pt).second;
        return 0;
    }
};
