template <typename Iter1, typename Iter2>
int count_subsegments(Iter1 first, Iter1 last, Iter2 cfirst, Iter2 clast) {
    int ans = 0;
    while (first != last) {
        auto tf = first, tcf = cfirst;
        bool check = 1;
        while (tf != last && tcf != clast) {
            if (*tf != *tcf) {
                check = 0;
                break;
            }
            ++tf;
            ++tcf;
        }
        if (check && tcf == clast) {
            ++ans;
        }
        ++first;
    }
    return ans;
}