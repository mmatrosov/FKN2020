#include <algorithm>
#include <vector>

void delete_zeroes(std::vector<int> &numbers) {
    auto it = std::remove(numbers.begin(), numbers.end(), 0);
    numbers.erase(it, numbers.end());
}