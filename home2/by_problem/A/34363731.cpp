#include <iostream>
#include <set>

int main() {
    int x;
    std::set<int> saw;
    while (std::cin >> x) {
        std::cout << (saw.find(x) == saw.end() ? "NO" : "YES") << '\n';
        saw.insert(x);
    }
    return 0;
}
