template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (first == last) {
        return first;
    }
    auto new_last = first;
    for (auto iter = first; iter != last; ++iter) {
        if (*iter != *new_last) {
            *(++new_last) = *iter;
        }
    }
    return ++new_last;
}
