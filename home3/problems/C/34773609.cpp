template <typename Iter>
Iter unique(Iter first, Iter last) {
    auto new_iter = first;
    for (auto iter = first; iter != last; ++iter) {
        if (iter == first) {
            *new_iter = *iter;
            ++new_iter;
        } else {
            auto prev_iter = iter;
            --prev_iter;
            if (*prev_iter != *iter) {
                *new_iter = *iter;
                ++new_iter;
            }
        }
    }
    return new_iter;
}