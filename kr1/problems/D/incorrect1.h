#include <algorithm>
#include <deque>

void RemoveDuplicates(std::deque<int>& d) {
  std::sort(d.begin(), d.end());
  d.erase(std::unique(d.begin(), d.end()), d.end());
}
