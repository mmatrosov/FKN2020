template <typename It1, typename It2>
bool check_subsegment(It1 begin, It1 end, It2 seg_begin, It2 seg_end) {
    bool check = true;
    It1 it1 = begin;
    It2 it2 = seg_begin;
    while (it1 != end && it2 != seg_end) {
        if (*it1 != *it2)
            return false;
        ++it1;
        ++it2;
    }
    if (it2 != seg_end)
        return false;
    return true;
}

template <typename It1, typename It2>
int count_subsegments(It1 first1, It1 last1, It2 first2, It2 last2) {
    int result = 0;
    for (It1 it = first1; it != last1; ++it) {
        result += check_subsegment(it, last1, first2, last2);
    }
    return result;
}
