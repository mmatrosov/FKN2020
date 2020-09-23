#include <deque>
#include <set>

void RemoveDuplicates(std::deque<int>& d) {
  std::set<int> s(d.begin(), d.end());
  d = std::deque(s.begin(), s.end());
}
