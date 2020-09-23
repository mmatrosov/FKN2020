#include <iostream>
#include <set>

signed main() {
    int number;
    std::set<int> prev_numbers;
    while (std::cin >> number) {
        if (prev_numbers.insert(number).second)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
}
