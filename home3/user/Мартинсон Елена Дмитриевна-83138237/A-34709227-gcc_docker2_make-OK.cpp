#include <iostream>

template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
  for (auto it = first; it != last; ++it) {
    if (f(*it)) {
      return true;
    }
  }
  return false;
}
