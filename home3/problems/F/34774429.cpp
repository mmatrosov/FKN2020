template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    auto out_iter = out;
    for (auto iter = first; iter != last; ++iter) {
        if (condition(*iter)) {
            *out_iter = f(*iter);
            ++out_iter;
        }
    }
    return out_iter;
}