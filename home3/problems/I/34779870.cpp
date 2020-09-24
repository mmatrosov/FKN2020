#include <iostream>
#include <vector>

template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    while (first1 != last1 && last2 != first2) {
        if (*first1 <= *(last2 - 1)) {
            *out++ = *first1;
            first1++;
        } else {
            last2--;
            *out++ = *last2;
        }
    }
    while (first1 != last1) {
        *out++ = *first1;
        first1++;
    }
    while (last2 != first2) {
        last2--;
        *out++ = *last2;
    }
    return out;
}
