#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::map <std::string, int64_t> sum_mark, num_mark;
    for (int i = 0; i < n; ++i) {
        std::string surn;
        int mark;
        std::cin >> surn >> mark;
        sum_mark[surn] += mark;
        ++num_mark[surn];
        std::cout << sum_mark[surn] / num_mark[surn] << '\n';
    }
    return 0;
}