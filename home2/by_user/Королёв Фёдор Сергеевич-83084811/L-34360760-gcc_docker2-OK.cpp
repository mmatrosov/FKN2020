#include <iostream>
#include <deque>

int main() {
    int n, k;
    std::cin >> n >> k;
    int a[n];
    std::deque <int> can_min;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        while (!can_min.empty() && can_min.back() > a[i]) {
            can_min.pop_back();
        }
        can_min.push_back(a[i]);
        if (i >= k - 1) {
            std::cout << can_min.front() << '\n';
            if (can_min.front() == a[i - (k - 1)]) {
                can_min.pop_front();
            }
        }
    }
    return 0;
}