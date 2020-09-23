template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    auto i1 = first1, i2 = last2;
    --i2;
    --first2;
    while (i1 != last1 || i2 != first2) {
        if (i1 == last1) {
            *out = *i2;
            ++out;
            --i2;
        } else if (i2 == first2) {
            *out = *i1;
            ++out;
            ++i1;
        } else if (*i1 < *i2) {
            *out = *i1;
            ++i1;
            ++out;
        } else {
            *out = *i2;
            --i2;
            ++out;
        }
    }
    return out;
}