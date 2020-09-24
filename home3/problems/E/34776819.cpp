#include <iostream>
#include <vector>

template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (last == first) {
        return out;
    }
    do {
        last--;
        *out++ = *last;
    } while (last != first);
    return out;
}
