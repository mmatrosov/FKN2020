template< class It, class T >
void fill_range(It first, It last, const T& value) {
    for (auto i = first; i != last; ++i) {
        *i = value;
    }
}