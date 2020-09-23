template<class It1, class It2>
It2 swap_segments(It1 first1, It1 last1, It2 first2) {
    auto it2 = first2;
    for (auto it1 = first1; it1 != last1; ++it1, ++it2) {
        auto temp = *it1;
        *it1 = *it2;
        *it2 = temp;
    }
    return it2;
}
