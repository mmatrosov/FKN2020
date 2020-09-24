template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for (InIter it = first; it != last; ++it) {
        if (condition(*it)) {
            *out = f(*it);
            ++out;
        }
    }
    return out;
}
