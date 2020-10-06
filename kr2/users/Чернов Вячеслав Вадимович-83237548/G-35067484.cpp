template <typename It1, typename It2>
int count_subsegments(It1 first1, It1 last1, It2 first2, It2 last2) {
    int result = 0;
    while (first1 != last1) {
        auto cur_it1 = first1;
        auto cur_it2 = first2;
        while (cur_it1 != last1 && cur_it2 != last2) {
            if (*cur_it1 != *cur_it2) {
                break;
            }
            ++cur_it1;
            ++cur_it2;
        }
        ++first1;
        result +=
        cur_it2 == last2;
    }
    return result;
}
