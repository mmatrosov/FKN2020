#include <iostream>
#include <string>
#include <vector>

const int maxn = 1e5 + 9;

signed main() {
    std::vector<int> next_elem(maxn, -1);
    std::vector<int> prev_elem(maxn, -1);
    int first_elem = -1;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num1, num2;
        std::cin >> num1 >> num2;
        if (num2 != first_elem && prev_elem[num2] == -1) {
            next_elem[num1] = first_elem;
            if (first_elem != -1)
                prev_elem[first_elem] = num1;
            first_elem = num1;
        } else {
            next_elem[num1] = next_elem[num2];
            if (next_elem[num1] != -1)
                prev_elem[next_elem[num1]] = num1;
            prev_elem[num1] = num2;
            next_elem[num2] = num1;
        }
    }
    int cur = first_elem;
    while (cur != -1) {
        std::cout << cur << "\n";
        cur = next_elem[cur];
    }
}
