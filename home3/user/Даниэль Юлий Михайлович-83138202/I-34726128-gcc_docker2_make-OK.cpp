template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    while (first1 != last1 || first2 != last2) {
        if (first2 != last2) {
            It r_first2 = last2;
            r_first2--;
            if (first1 != last1) {
                if (*first1 < *r_first2)
                    *out++ = *first1++;
                else
                    *out++ = *r_first2--;
            } else {
                *out++ = *r_first2--;
            }
            last2 = ++r_first2;
        } else {
            *out++ = *first1++;
        }
    }
    return out;
}