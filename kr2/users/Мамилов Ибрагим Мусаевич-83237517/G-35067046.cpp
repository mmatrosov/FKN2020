template <typename Iter1, typename Iter2>
int count_subsegments(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2) {
    int count = 0;
    for (Iter1 it1 = first1; it1 != last1; ++it1) {
        bool hasDiff = 0;
        Iter1 tempIt1 = it1;
        for (Iter2 it2 = first2; it2 != last2; ++it2) {
            if (tempIt1 == last1)
                return count;
            if (*(tempIt1++) != *it2) {
                hasDiff = 1;
                break;
            }
        }
        if (!hasDiff)
            ++count;
    }
    return count;
}