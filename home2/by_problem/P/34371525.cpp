#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
    if (a == 0) return 0;
    return 1;
}

void delete_zeroes(std::vector <int> &numbers) {
    std::stable_sort(numbers.begin(), numbers.end(), cmp);
    numbers.erase(std::find(numbers.begin(), numbers.end(), 0), numbers.end());
    std::reverse(numbers.begin(), numbers.end());
}