#include <algorithm>
#include <iostream>
#include <vector>


void delete_zeroes(std::vector<int>& numbers) {
  auto iter = std::remove(numbers.begin(), numbers.end(), 0);
  numbers.erase(numbers.begin(), iter);
}
