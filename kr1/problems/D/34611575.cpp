#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>


void RemoveDuplicates(std::deque<int>& data) {
    auto it = std::unique(data.begin(), data.end());
    data.erase(it, data.end());
}
