#include <iostream>
#include <string>
#include <deque>

signed main() {
    int n;
    std::cin >> n;
    std::deque<std::string> works;
    for (int i = 0; i < n; ++i) {
        std::string surname, type;
        std::cin >> surname >> type;
        if (type == "top")
            works.push_front(surname);
        else
            works.push_back(surname);
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int number;
        std::cin >> number;
        std::cout << works[number - 1] << "\n";
    }
}
