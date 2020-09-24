template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (first == last) {
        return out;
    }
    InIter rbegin = last;
    rbegin--;
    while (rbegin != first) {
        *out = *rbegin;
        out++;
        rbegin--;
    }
    *out = *rbegin;
    out++;
    return out;
}
