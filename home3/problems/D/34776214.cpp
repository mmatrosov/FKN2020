#include <iostream>
#include <vector>

template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 == *first2) {
            ++first1;
            ++first2;
        } else if (*first1 > *first2) {
            ++first2;
        } else {
            *out++ = *first1;
            ++first1;
        }
    }
    while (first1 != last1) {
        *out++ = *first1;
        first1++;
    }
    return out;
}
