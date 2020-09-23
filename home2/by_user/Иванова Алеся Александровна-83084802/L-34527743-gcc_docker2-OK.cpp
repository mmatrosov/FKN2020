#include <iostream>
#include <vector>
#include <deque>

signed main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::deque<int> min_elements;
    for (int i = 0; i < n; ++i) {
        if (i - k >= 0 && min_elements.front() == a[i - k])
            min_elements.pop_front();
        while (!min_elements.empty() && min_elements.back() > a[i])
            min_elements.pop_back();
        min_elements.push_back(a[i]);
        if (i >= k - 1)
            std::cout << min_elements.front() << "\n";
    }
}
