#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;
    int number;
    while (std::cin >> number) {
        if (numbers.count(number) > 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
        numbers.insert(number);
    }
}
