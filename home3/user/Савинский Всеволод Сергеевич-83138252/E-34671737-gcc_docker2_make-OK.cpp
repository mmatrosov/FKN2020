template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (first == last) {
        return out;
    }
    auto iter = last;
    do {
        *(out++) = *(--iter);
    } while (iter != first);
    return out;
}
