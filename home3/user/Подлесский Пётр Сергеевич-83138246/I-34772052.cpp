#include <iostream>

template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    It it1 = first1;
    last2--;
    first2--;
    It it2 = last2;
    while (it1 != last1 && it2 != first2) {
        if (*it1 <= *it2) {
            *out++ = *it1++;
        } else {
            *out++ = *it2--;
        }
    }
    while (it1 != last1) {
        *out++ = *it1++;
    }
    while (it2 != first2) {
        *out++ = *it2--;
    }
    return out;
}
