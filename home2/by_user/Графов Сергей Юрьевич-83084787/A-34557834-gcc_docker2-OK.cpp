#include<iostream>
#include<set>

int main() {
    std::set<int> were;
    int x;
    while (std::cin >> x) {
        if (were.find(x) == were.end()) {
            std::cout << "NO\n";
            were.insert(x);
        } else {
            std::cout << "YES\n";
        }
    }
}
