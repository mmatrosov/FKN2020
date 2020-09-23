#include <deque>

void RemoveDuplicates(std::deque<int>& data) {
    int n = data.size();
    for (int i = 0; i < n; i++) {
        int x = data.front();
        data.pop_front();
        if (data.empty() || x != data.back())
            data.push_back(x);
    }
}