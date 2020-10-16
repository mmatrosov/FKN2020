#include <set>
#include <utility>

class Stock {
private:
    std::set <std::pair <std::pair <int, int>, int> > s1, s2;
    int num = 0;

public:
    void add(int w, int v) {
        s1.insert({{w, -num}, v});
        s2.insert({{v, -num}, w});
        ++num;
    }

    int get_by_w(int min_w) {
        auto it = s1.lower_bound({{min_w, -num - 1}, 0});
        if (it == s1.end()) {
            return -1;
        }
        auto ans = it->first.second;
        s2.erase({{it->second, it->first.second}, it->first.first});
        s1.erase(*it);
        return -ans;
    }

    int get_by_v(int min_v) {
        auto it = s2.lower_bound({{min_v, -num - 1}, 0});
        if (it == s2.end()) {
            return -1;
        }
        auto ans = it->first.second;
        s1.erase({{it->second, it->first.second}, it->first.first});
        s2.erase(*it);
        return -ans;
    }
};