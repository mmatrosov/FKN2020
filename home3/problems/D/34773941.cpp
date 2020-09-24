template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    auto it2 = first2;
    auto out_it = out;
    for (auto it1 = first1; it1 != last1; ++it1) {
        while (it2 != last2 && *it2 < *it1)
            ++it2;
        if (it2 != last2 && *it2 == *it1) {
            ++it2;
        } else {
            *out_it = *it1;
            ++out_it;
        }
    }
    return out_it;
}