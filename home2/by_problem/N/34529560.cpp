#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

signed main() {
    std::string contest;
    while (getline(std::cin, contest)) {
        int pos = 0;
        int id = 0;
        while (isdigit(contest[pos])) {
            id = id * 10 + (contest[pos] - '0');
            ++pos;
        }
        int cnt = 0;
        ++pos;
        while (pos < contest.size() && isdigit(contest[pos])) {
            cnt = cnt * 10 + (contest[pos] - '0');
            ++pos;
        }
        ++pos;
        std::vector<int> task;
        bool is_alpha = false;
        while (pos < contest.size()) {
            if (isalpha(contest[pos])) {
                is_alpha = true;
                task.push_back(contest[pos]);
                pos += 2;
            } else {
                int x = 0;
                while (pos < contest.size() && isdigit(contest[pos])) {
                    x = x * 10 + (contest[pos] - '0');
                    ++pos;
                }
                task.push_back(x);
                ++pos;
            }
        }
        std::sort(task.begin(), task.end());
        std::cout << id << " ";
        if (is_alpha) {
            int pt = 0;
            for (char c = 'A'; c < 'A' + cnt; ++c) {
                if (pt < task.size() && task[pt] == c)
                    pt++;
                else
                    std::cout << c << " ";
            }
        } else {
            int pt = 0;
            for (int c = 1; c <= cnt; ++c) {
                if (pt < task.size() && task[pt] == c)
                    pt++;
                else
                    std::cout << c << " ";
            }
        }
        std::cout << "\n";
    }
}
