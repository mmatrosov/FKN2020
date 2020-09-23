#include <deque>

void RemoveDuplicates(std::deque <int>& d) {
    if (d.empty()) {
        return;
    }
    int val = d.front() - 1, ds = d.size();
    for (int i = 0; i < ds; ++i) {
        if (d.front() != val) {
            val = d.front();
            d.push_back(d.front());
            d.pop_front();
        } else {
            d.pop_front();
        }
    }
}