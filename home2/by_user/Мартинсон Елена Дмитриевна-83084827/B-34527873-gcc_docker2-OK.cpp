#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    char op_type;
    std::unordered_multiset<std::string> all;
    while (std::cin >> op_type) {
        if (op_type == '#') {
            break;
        }
        std::string now;
        std::cin >> now;
        if (op_type == '+') {
            all.insert(now);
        } else if (op_type == '-') {
            all.erase(now);
        } else {
            if (all.find(now) != all.end()) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}
