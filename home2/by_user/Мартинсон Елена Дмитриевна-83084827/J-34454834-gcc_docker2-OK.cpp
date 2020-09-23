#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

struct quest{
    int place;
    int num;
};

bool operator<(quest a, quest b) {
    return a.place < b.place;
}

int main() {
    int n;
    std::cin >> n;
    std::deque<std::string> stack;
    for (int i = 0; i < n; ++i) {
        std::string surname, type;
        std::cin >> surname >> type;
        if (type == "top") {
            stack.push_front(surname);
        } else {
            stack.push_back(surname);
        }
    }
    int m;
    std::cin >> m;
    std::vector<quest> q(m);
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        q[i] = {x - 1, i};
    }
    std::sort(q.begin(), q.end());
    std::vector<std::string> ans(m);
    int cnt = 0;
    int now = 0;
    while (!stack.empty() && cnt != m) {
        while (now == q[cnt].place) {
            ans[q[cnt].num] = stack.front();
            cnt += 1;
        }
        stack.pop_front();
        now += 1;
    }
    for (auto& el : ans) {
        std::cout << el << "\n";
    }

    return 0;
}
