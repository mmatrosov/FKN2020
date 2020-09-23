#include <iostream>
#include <deque>

void RemoveDuplicates(std::deque<int>& data) {
    if (data.size() == 0)
        return;
    int cur_n = data[0];
    size_t sz = data.size();
    data.push_back(cur_n);
    for (size_t i = 1; i < sz; ++i) {
        if (data[i] == cur_n)
            continue;
        data.push_back(data[i]);
        cur_n = data[i];
    }
    for (size_t i = 0; i < sz; ++i)
        data.pop_front();
}
