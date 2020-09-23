#include <iostream>
#include <set>

int main() {
    int x;
    std::set<int> already_met;
    while (std::cin >> x) {
        if (already_met.find(x) != already_met.end())
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;

        already_met.insert(x);
    }
    return 0;
}