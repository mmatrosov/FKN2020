#include <set>
#include <vector>
#include <tuple>

struct Box {
    int volume, weight, index;

    Box(int vol0, int wei0, int ind0) : volume(vol0), weight(wei0), index(ind0) {
    }
};

struct LessVolume {
    bool operator()(const Box& a, const Box& b) const {
        return std::tie(a.volume, b.index) < std::tie(b.volume, a.index);
    }
};

struct LessWeight {
    bool operator()(const Box& a, const Box& b) const {
        return std::tie(a.weight, b.index) < std::tie(b.weight, a.index);
    }
};

class Stock {
    std::vector<Box> boxes;
    std::set<Box, LessVolume> minVolumeSet;
    std::set<Box, LessWeight> minWeightSet;

    int give(int index) {
        minVolumeSet.erase(boxes[index]);
        minWeightSet.erase(boxes[index]);
        return index;
    }

public:
    void add(int w, int v) {
        boxes.emplace_back(v, w, boxes.size());
        minVolumeSet.insert(boxes.back());
        minWeightSet.insert(boxes.back());
    }

    int get_by_w(int min_w) {
        auto it = minWeightSet.lower_bound(Box(0, min_w, boxes.size()));
        if (it == minWeightSet.end())
            return -1;
        return give(it->index);
    }

    int get_by_v(int min_v) {
        auto it = minVolumeSet.lower_bound(Box(min_v, 0, boxes.size()));
        if (it == minVolumeSet.end())
            return -1;
        return give(it->index);
    }
};