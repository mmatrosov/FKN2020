#include <iostream>
#include <utility>

template <typename Iter>
Iter unique(Iter first, Iter last) {
  if (first == last) {
    return first;
  }
  auto it = first++;
  while (first != last) {
    if (*it != *first) {
      ++it;
      std::swap(*it, *first);
    }
    ++first;
  }
  return ++it;
}
