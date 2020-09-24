#include <algorithm>

template<class It1, class It2>
It2 swap_segments(It1 first1, It1 last1, It2 first2) {
    for (auto i = first1; i!= last1; ++i) {
        std::swap(*i, *first2);
        ++first2;
    }
    return first2;
}