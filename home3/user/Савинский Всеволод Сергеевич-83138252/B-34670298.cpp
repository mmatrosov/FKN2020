template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
    for (auto iter = first; iter != last; ++iter) {
        if (!f(*iter)) {
            *(out++) = *iter;
        }
    }
    return out;
}
