template<typename Iter1, typename Iter2>
int count_subsegments(Iter1 begin1, Iter1 end1, Iter2 begin2, Iter2 end2) {
    int res = 0;
    for (auto it = begin1; it != end1; ++it) {
        auto pt1 = it;
        auto pt2 = begin2;
        while (pt1 != end1 && pt2 != end2 && *pt1 == *pt2) {
            ++pt1;
            ++pt2;
        }
        if (pt2 == end2)
            ++res;
    }
    return res;
}