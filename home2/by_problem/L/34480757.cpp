#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int &el : arr) {
        std::cin >> el;
    }
    std::deque<int> q;
    for (size_t i = 0; i < n; ++i) {
        while (!q.empty() && q.back() > arr[i]) {
            q.pop_back();
        }
        q.push_back(arr[i]);
        if (k <= i && q.front() == arr[i - k]) {
            q.pop_front();
        }
        if (k - 1 <= i) {
            std::cout << q.front() << std::endl;
        }
    }
}
