#include <iostream>
#include <set>
#include <tuple>
#include <unordered_map>

struct Box {
    int weight, volume, index;
};

bool operator<(const Box& a, const Box& b) {
    return std::tie(a.weight, a.volume, a.index) < std::tie(b.weight, b.volume, b.index);
}

struct Elem {
    int value, index;
};

bool operator<(const Elem& a, const Elem& b) {
    return std::tie(a.value, b.index) < std::tie(b.value, a.index);
}

class Stock {
private:
    int containers = 0;
    std::set<Elem> sortByWeight;
    std::set<Elem> sortByVolume;
    std::unordered_map<int, Box> params;

public:
    void add(int w, int v) {
        params[containers] = {w, v, containers};
        sortByWeight.insert({w, containers});
        sortByVolume.insert({v, containers});
        ++containers;
    }

    int get_by_w(int min_w) {
        auto it = sortByWeight.upper_bound({min_w - 1, -1});
        if (it == sortByWeight.end()) {
            return -1;
        }
        int index = (*it).index;
        sortByVolume.erase({params[index].volume, index});
        sortByWeight.erase(it);
        params.erase(index);
        return index;
    }

    int get_by_v(int min_v) {
        auto it = sortByVolume.upper_bound({min_v - 1, -1});
        if (it == sortByVolume.end()) {
            return -1;
        }
        int index = (*it).index;
        sortByWeight.erase({params[index].weight, index});
        sortByVolume.erase(it);
        params.erase(index);
        return index;
    }
};