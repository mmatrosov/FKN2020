#include <iostream>
#include <string>
#include <string_view>
#include <map>
#include <vector>
#include <algorithm>

struct ans {
    std::string_view str;
    int oft;
    ans(std::string_view str0, int oft0) {
        str = str0;
        oft = oft0;
    }
};

bool operator< (ans& a, ans& b) {
    if (a.oft == b.oft) return a.str < b.str;
    return a.oft > b.oft;
}

int main() {
    std::map<std::string_view, int> counter;
    int n_ws, ngr;
    std::cin >> n_ws >> ngr;
    std::string allws;
    std::vector<int> starts, ends;

    for (int i = 0; i < n_ws; ++i) {
        allws += " ";
        starts.push_back(allws.size());
        std::string word;
        std::cin >> word;
        allws += word;
        ends.push_back(allws.size());
    }

    std::string_view myview(allws);
    for (int i = ngr - 1; i < n_ws; ++i) {
        counter[myview.substr(starts[i - ngr + 1], ends[i] - starts[i - ngr + 1])]++;
    }

    std::vector<ans> res;

    for (auto [str, i] : counter) {
        res.emplace_back(str, i);
    }

    std::sort(res.begin(), res.end());
    for (auto i : res) {
        std::cout << i.str << " - " << i.oft << std::endl;
    }
    return 0;
}