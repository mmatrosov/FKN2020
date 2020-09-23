#include <iostream>
#include <set>

int main() {
    std::set<int> values;

    int num;
    while (std::cin >> num) {
        std::cout << (values.insert(num).second ? "NO" : "YES") << std::endl;
    }
}
