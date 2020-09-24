#include <iostream>

template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
  if (first == last) {
    return out;
  }
  do {
    --last;
    *out = *last;
    ++out;
  } while (first != last);
  return out;
}
