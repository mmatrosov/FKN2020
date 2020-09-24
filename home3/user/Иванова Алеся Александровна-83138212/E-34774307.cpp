template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    if (first == last)
        return out;
    auto out_iter = out;
    auto iter = last;
    --iter;
    while (true) {
        *out_iter = *iter;
        ++out_iter;
        if (iter == first)
            break;
        --iter;
    }
    return out_iter;
}