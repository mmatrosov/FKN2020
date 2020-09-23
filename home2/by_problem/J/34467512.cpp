#include <iostream>
#include <string>
#include <deque>

int main() {
    size_t n;
    std::cin >> n;

    std::deque<std::string> order;
    for (size_t i = 0; i < n; ++i) {
        std::string name, type;
        std::cin >> name >> type;
        type == "top" ? order.push_front(name) : order.push_back(name);
    }

    size_t m;
    std::cin >> m;
    for (size_t i = 0; i < m; ++i) {
        size_t x;
        std::cin >> x;
        std::cout << order[x - 1] << std::endl;
    }
}
