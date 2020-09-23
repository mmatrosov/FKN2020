#include <algorithm>
#include <deque>
#include <iostream>

void RemoveDuplicates(std::deque<int>& data) {
    data.resize(std::unique(data.begin(), data.end()) - data.begin());
}
