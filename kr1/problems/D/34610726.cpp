#include <deque>
#include <algorithm>

void RemoveDuplicates(std::deque<int>& data) {
    auto new_end = std::unique(data.begin(), data.end());
    data.erase(new_end, data.end());
}
