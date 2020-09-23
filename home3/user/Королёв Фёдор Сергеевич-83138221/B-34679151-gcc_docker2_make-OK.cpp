template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
    for (auto i = first; i != last; ++i) {
        if (!f(*i)) {
            *out = *i;
            ++out;
        }
    }
    return out;
}