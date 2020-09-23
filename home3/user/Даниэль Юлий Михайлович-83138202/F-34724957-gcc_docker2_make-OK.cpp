template <typename InIter, typename OutIter, typename Predicate, typename Action>
OutIter transform_if(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    for (; first != last; ++first)
        if (condition(*first))
            *out++ = f(*first);
    return out;
}