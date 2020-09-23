#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>

struct str{
    std::deque<std::string> deq;
    int cnt;
};

bool operator<(str a, str b) {
    if (a.cnt == b.cnt) {
        return a.deq < b.deq;
    }
    return a.cnt > b.cnt;
}

void print(std::deque<std::string> deq) {
    for (auto i = deq.begin(); i != deq.end(); ++i) {
        std::cout << *i << " ";
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    if (m < n) {
        return 0;
    }
    n--;
    std::map<std::deque<std::string>, int> n_gram;
    std::deque<std::string> cur;
    for (int i = 0; i < n; ++i) {
        std::string now;
        std::cin >> now;
        cur.push_back(now);
    }
    for (int i = n; i < m; ++i) {
        std::string now;
        std::cin >> now;
        cur.push_back(now);
        n_gram[cur] += 1;
        cur.pop_front();
    }
    std::vector<str> final_res;

    for (const auto& [key, val] : n_gram) {
        final_res.push_back({key, val});
    }
    std::sort(final_res.begin(), final_res.end());
    for (const auto& i : final_res) {
        print(i.deq);
        std::cout << "- " << i.cnt << "\n";
    }



    return 0;
}
