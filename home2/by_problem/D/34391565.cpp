#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

signed main() {
    std::vector<std::string> ways;
    std::string way;
    while (std::cin >> way) {
        int pos = way.rfind('/');
        ways.push_back(way.substr(0, pos + 1));
    }
    ways.push_back("");
    std::sort(ways.begin(), ways.end());
    for (int i = 1; i < ways.size(); i++) {
        bool is_equal = true;
        way = ways[i];
        std::string prev_way = ways[i - 1];
        for (int e = 0; e < way.size(); e++) {
            if (e >= prev_way.size() || prev_way[e] != way[e])
                is_equal = false;
            if (!is_equal && way[e] == '/')
                std::cout << way.substr(0, e + 1) << "\n";
        }
    }
}
