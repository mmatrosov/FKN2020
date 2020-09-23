#include <algorithm>
#include <iostream>
#include <vector>

void delete_zeroes(std::vector<int>& numbers) {
    int zeroesCount = std::count(numbers.begin(), numbers.end(), 0);
    std::vector<int> noZeroes(numbers.size() - zeroesCount);
    std::copy_if(numbers.begin(), numbers.end(), noZeroes.begin(), [](int x) { return x != 0; });
    numbers.swap(noZeroes);
}
