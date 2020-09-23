#include <iostream>
#include <deque>

void RemoveDuplicates(std::deque<int>& data) {
    if (data.size() == 0)
        return;
    int cur_n = data[0];
    size_t sz = data.size();
    data.push_back(cur_n);
    data.pop_front();
    for (size_t i = 1; i < sz; ++i) {
        if (data[0] == cur_n) {
            data.pop_front();
            continue;
        }
        data.push_back(data[0]);
        data.pop_front();
        cur_n = data[0];
    }
}
