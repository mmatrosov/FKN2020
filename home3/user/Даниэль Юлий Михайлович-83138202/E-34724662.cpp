template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (first == last) return out;
    --last;
    for (; last != first; --last)
        *out++ = *last;
    *out++ = *first;
    return out;
}