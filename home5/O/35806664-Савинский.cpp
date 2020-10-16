#include <iostream>
#include <set>
#include <tuple>

class Stock {
    struct Box {
        int t1, id, t2;

        bool operator<(const Box& other) const {
            return std::tie(t1, other.id, t2) < std::tie(other.t1, id, other.t2);
        }
    };
    std::set<Box> sorted_by_w, sorted_by_v;
    int id = 0;

   public:
    void add(int w, int v) {
        sorted_by_w.insert({w, id, v});
        sorted_by_v.insert({v, id, w});
        id += 1;
    }

    int get_by_w(int min_w) {
        auto iter = sorted_by_w.lower_bound({min_w, id + 1, 0});
        if (iter == sorted_by_w.end()) {
            return -1;
        }
        auto [w, id, v] = *iter;
        sorted_by_w.erase(iter);
        sorted_by_v.erase(sorted_by_v.find({v, id, w}));
        return id;
    }

    int get_by_v(int min_v) {
        std::swap(sorted_by_w, sorted_by_v);
        int res = get_by_w(min_v);
        std::swap(sorted_by_w, sorted_by_v);
        return res;
    }
};
