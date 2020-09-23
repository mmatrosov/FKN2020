#include <algorithm>
#include <deque>

void RemoveDuplicates(std::deque<int>& d) {
  d.erase(std::unique(d.begin(), d.end()), d.end());
}
