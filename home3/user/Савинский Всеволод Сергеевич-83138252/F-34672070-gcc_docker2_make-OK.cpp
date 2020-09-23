template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for (auto iter = first; iter != last; ++iter) {
        if (condition(*iter)) {
            *(out++) = f(*iter);
        }
    }
    return out;
}
