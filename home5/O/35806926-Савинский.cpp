#include <iostream>
#include <set>
#include <utility>

class Stock {
    std::set<std::pair<int, int>> sorted_by_w, sorted_by_v;
    std::set<int> to_delete;
    int id = 0;

   public:
    void add(int w, int v) {
        sorted_by_w.emplace(w, -id);
        sorted_by_v.emplace(v, -id);
        id += 1;
    }

    int get_by_w(int min_w) {
        auto iter = sorted_by_w.lower_bound({min_w - 1, 1});
        while (iter != sorted_by_w.end()) {
            auto to_del_iter = to_delete.find(iter->second);
            if (to_del_iter == to_delete.end()) {
                break;
            }
            iter = sorted_by_w.erase(iter);
            to_delete.erase(to_del_iter);
        }
        if (iter == sorted_by_w.end()) {
            return -1;
        }
        int res = iter->second;
        to_delete.insert(res);
        sorted_by_w.erase(iter);
        return -res;
    }

    int get_by_v(int min_v) {
        std::swap(sorted_by_w, sorted_by_v);
        int res = get_by_w(min_v);
        std::swap(sorted_by_w, sorted_by_v);
        return res;
    }
};
