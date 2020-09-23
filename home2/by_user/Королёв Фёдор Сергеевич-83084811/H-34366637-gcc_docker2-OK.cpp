#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::map <std::string, std::vector <std::pair <int, int> > > res;
    for (int i = 0; i < n; ++i) {
        int part;
        std::cin >> part;
        for (int j = 0; j < part; ++j) {
            std::string surn;
            int bal;
            std::cin >> surn >> bal;
            res[surn].push_back({bal, i});
        }
    }
    for (auto guy : res) {
        std::cout << guy.first << '\t';
        int id = 0;
        for (auto el : guy.second) {
            while (id < el.second) {
                ++id;
                std::cout << "0\t";
            }
            ++id;
            std::cout << el.first << '\t';
        }
        while (id < n) {
            std::cout << "0\t";
            ++id;
        }
        std::cout << '\n';
    }
    return 0;
}