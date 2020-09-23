#include <iostream>
#include <vector>
#include <algorithm>

void delete_zeroes(std::vector<int>& numbers) {
    auto iter = std::remove(numbers.begin(), numbers.end(), 0);
    numbers.resize(iter - numbers.begin());
}
