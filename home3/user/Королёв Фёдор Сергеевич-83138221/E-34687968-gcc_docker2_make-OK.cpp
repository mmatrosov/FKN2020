template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    for (auto i = last; i != first; --i) {
        --i;
        *out = *i;
        ++out;
        ++i;
    }
    return out;
}