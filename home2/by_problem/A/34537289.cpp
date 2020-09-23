#include <iostream>
#include <set>

int main() {
    std::set<int> usedIntegers;
    int newInt;
    while (std::cin >> newInt) {
        if (usedIntegers.find(newInt) != usedIntegers.end())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
        usedIntegers.insert(newInt);
    }
    return 0;
}