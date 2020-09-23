#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::multiset<int> window;
    std::vector <int> array(n);
    for (int i = 0; i < n; i++)
        std::cin >> array[i];
    for (int i = 0; i < k; i++)
        window.insert(array[i]);
    std::cout << *window.begin() << '\n';
    for (int i = k; i < n; i++) {
        window.erase(window.find(array[i - k]));
        window.insert(array[i]);
        std::cout << *window.begin() << '\n';
    }
}
