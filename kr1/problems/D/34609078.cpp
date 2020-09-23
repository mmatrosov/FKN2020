#include <iostream>
#include <deque>
#include <algorithm>

void RemoveDuplicates(std::deque<int>& data) {
    auto iter = unique(data.begin(), data.end());
    data.erase(iter, data.end());
}