template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (first == last) return first;
    for (Iter it = first; it != last; ++it) {
        if (*first != *it) std::swap(*it, *++first);
    }
    return ++first;
}