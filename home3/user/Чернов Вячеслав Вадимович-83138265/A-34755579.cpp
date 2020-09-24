#include <iostream>

template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
  while (first != last) {
    if (f(*first)) {
      return true;
    }
    ++first;
  }
  return false;
}
