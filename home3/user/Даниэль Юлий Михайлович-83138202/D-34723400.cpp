template <typename InIter1, typename InIter2, typename OutIter>
OutIter set_difference(InIter1 first1, InIter1 last1, InIter2 first2, InIter2 last2, OutIter out) {
    for (; (first1 != last1); ++first1) {
        while ((first2 != last2) && (*first2 < *first1))
            ++first2;
        if ((first2 == last2) || (*first1 != *first2))
            *out++ = *first1;
        if ((first2 != last2) && (*first1 == *first2))
            first2++;
    }

    return out;
}