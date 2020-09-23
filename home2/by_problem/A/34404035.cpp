#include <iostream>
#include <set>

int main() {
    int num;
    std::set<int> seen_before;
    while (std::cin >> num) {
        if (seen_before.insert(num).second) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }
}