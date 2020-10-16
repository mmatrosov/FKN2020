#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

class Stock {
private:
    int cnt = 0;
    std::set<std::pair<int, int>> sorted_by_w;
    std::set<std::pair<int, int>> sorted_by_v;
    std::vector<std::pair<int, int>> elem;

public:
    void add(int w, int v) {
        elem.emplace_back(w, v);
        sorted_by_w.emplace(w, -cnt);
        sorted_by_v.emplace(v, -cnt);
        ++cnt;
    }

    int get_by_w(int min_w) {
        auto iter = sorted_by_w.lower_bound(std::make_pair(min_w, -cnt));
        if (iter == sorted_by_w.end())
            return -1;
        int ans_id = -(*iter).second;
        sorted_by_w.erase(iter);
        sorted_by_v.erase(std::make_pair(elem[ans_id].second, -ans_id));
        return ans_id;
    }

    int get_by_v(int min_v) {
        auto iter = sorted_by_v.lower_bound(std::make_pair(min_v, -cnt));
        if (iter == sorted_by_v.end())
            return -1;
        int ans_id = -(*iter).second;
        sorted_by_v.erase(iter);
        sorted_by_w.erase(std::make_pair(elem[ans_id].first, -ans_id));
        return ans_id;
    }
};