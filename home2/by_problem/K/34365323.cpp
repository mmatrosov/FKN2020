#include <map>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::map <int, int> right;
    right[-1] = -1;
    for (int i = 0; i < n; ++i) {
        int num, left;
        std::cin >> num >> left;
        if (!right[left]) {
            right[num] = right[-1];
            right[-1] = num;
        } else {
            right[num] = right[left];
            right[left] = num;
        }
    }
    int num = -1;
    while (right[num] != -1) {
        std::cout << right[num] << '\n';
        num = right[num];
    }
    return 0;
}