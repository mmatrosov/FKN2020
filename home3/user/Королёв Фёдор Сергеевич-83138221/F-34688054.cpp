template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for (auto i = first; i != last; ++i) {
        if (condition(*i)) {
            *out = f(*i);
            ++out;
        }
    }
    return out;
}