#include <algorithm>
#include <iostream>
#include <deque>

void RemoveDuplicates(std::deque<int>& data) {
    data.erase(std::unique(data.begin(), data.end()), data.end());
}
