template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (first == last) {
        return last;
    }
    auto val = *first;
    ++first;
    int erased = 0;
    for (auto i = first; i != last; ++i) {
        if (val != *i) {
            val = *i;
            *first = val;
            ++first;
        } else {
            ++erased;
        }
    }
    while (erased) {
        --last;
        --erased;
    }
    return last;
}