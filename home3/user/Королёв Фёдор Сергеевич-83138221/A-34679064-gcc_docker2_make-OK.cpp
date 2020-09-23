template <typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
    for (auto i = first; i != last; ++i) {
        if (f(*i)) {
            return 1;
        }
    }
    return 0;
}