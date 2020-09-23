#include <iostream>
#include <deque>
#include <algorithm>

void RemoveDuplicates(std::deque<int>& data) {
    data.resize(std::unique(data.begin(), data.end()) - data.begin());
}

