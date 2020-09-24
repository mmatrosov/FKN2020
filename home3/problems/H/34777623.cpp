#include <iostream>

template<class It1, class It2>
It2 swap_segments(It1 first1, It1 last1, It2 first2) {
    for (auto it = first1; it != last1; ++it) {
        std::swap(*it, *first2);
        first2++;
    }
    return first2;
}
