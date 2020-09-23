#include <iostream>
#include <vector>
#include <set>

const int MXN = 1000 + 10;

int main() {
    int n;
    std::vector<std::set<std::string>> enumerator(MXN);

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string word;
        int page_num;

        std::cin >> word >> page_num;
        enumerator[page_num].insert(word);
    }

    for (int i = 0; i < MXN; ++i) {
        if (enumerator[i].empty()) continue;
        std::cout << i << ' ';
        for (auto it = enumerator[i].begin(); it != enumerator[i].end(); ++it) {
            if (it != enumerator[i].begin()) std::cout << ' ';
            std::cout << (*it);
        }
        std::cout << std::endl;
    }
    return 0;
}