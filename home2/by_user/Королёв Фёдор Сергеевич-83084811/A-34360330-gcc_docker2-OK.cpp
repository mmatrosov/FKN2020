#include <iostream>
#include <set>

int main() {
    int val;
    std::set <int> s;
    while (std::cin >> val) {
        if (s.find(val) == s.end()) {
            std::cout << "NO\n";
            s.insert(val);
        } else {
            std::cout << "YES\n";
        }
    }
}