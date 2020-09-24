template <typename InIter, typename OutIter, typename Predicate>
OutIter remove_copy_if(InIter first, InIter last, OutIter out, Predicate f) {
    auto copy_iter = out;
    for (auto iter = first; iter != last; ++iter) {
        if (!f(*iter)) {
            *copy_iter = *iter;
            ++copy_iter;
        }
    }
    return copy_iter;
}