#include <algorithm>

template<class It1, class It2>
It2 swap_segments(It1 first1, It1 last1, It2 first2) {
    It2 it2 = first2;
    for (It1 it1 = first1; it1 != last1; ++it1) {
        std::swap(*it1, *it2);
        it2++;
    }
    return it2;
}
