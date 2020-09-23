template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    auto i1 = first1, i2 = first2;
    while (i1 != last1) {
        while (i2 != last2 && *i2 < *i1) {
            ++i2;
        }
        if (i2 == last2 || *i1 < *i2) {
            *out = *i1;
            ++out;
        } else {
            ++i2;
        }
        ++i1;
    }
    return out;
}