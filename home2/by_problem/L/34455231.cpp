#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

struct my_pair {
    int x;
    int num;
};

void push(std::deque<my_pair> &q, my_pair a) {
    while (!q.empty()) {
        my_pair now = q.front();
        if (now.x > a.x) {
            q.pop_front();
        } else {
            break;
        }
    }
    q.push_front(a);
}

int get(std::deque<my_pair> &q, int border) {
    while (q.back().num <= border) {
        q.pop_back();
    }
    return q.back().x;
}


int main() {
    int n, k;
    std::cin >> n >> k;
    std::deque<my_pair> mini;
    for (int i = 0; i < k - 1; ++i) {
        int a;
        std::cin >> a;
        push(mini, {a, i});
    }
    for (int i = k - 1; i < n; ++i) {
        int a;
        std::cin >> a;
        push(mini, {a, i});
        std::cout << get(mini, i - k) << "\n";
    }

    return 0;
}
