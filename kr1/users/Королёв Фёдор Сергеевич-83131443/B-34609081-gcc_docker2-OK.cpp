#include <iostream>
#include <map>
#include <string>

int main() {
    int m;
    std::cin >> m;
    std::map <int, std::map<int, std::string> > tabl;
    for (int i = 0; i < m; ++i) {
        int w;
        std::cin >> w;
        for (int j = 0; j < w; ++j) {
            std::string s;
            std::cin >> s;
            tabl[j][i] = s;
        }
    }
    for (auto str : tabl) {
        int id = 0;
        for (auto el : str.second) {
            while (el.first > id) {
                ++id;
                std::cout << '\t';
            }
            std::cout << el.second << '\t';
            ++id;
        }
        std::cout << '\n';
    }
    return 0;
}