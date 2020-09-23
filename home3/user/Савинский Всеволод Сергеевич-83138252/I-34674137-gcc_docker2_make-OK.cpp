template <typename It, typename OutputIt>
OutputIt sideways_merge(It first1, It last1, It first2, It last2, OutputIt out) {
    for (auto it1 = first1, it2 = last2; it1 != last1 || it2 != first2; ) {
        if (it1 == last1 || (it2 != first2 && *prev(it2) < *it1)) {
            *(out++) = *(--it2);
        } else {
            *(out++) = *(it1++);
        }
    }
    return out;
}
