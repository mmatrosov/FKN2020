template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    for (auto it1 = first1, it2 = first2; it1 != last1; ++it1) {
        while (it2 != last2 && *it1 > *it2) {
            ++it2;
        }
        if (it2 != last2 && *it1 == *it2) {
            ++it2;
        } else {
            *(out++) = *it1;
        }
    }
    return out;
}
