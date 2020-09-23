#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void delete_zeroes(vector<int> &numbers) {
    auto it = remove(numbers.begin(), numbers.end(), 0);
    numbers.resize(it - numbers.begin());
}
