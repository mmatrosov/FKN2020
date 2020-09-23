template< class It, class T >
void fill_range(It first, It last, const T& value) {
    for (auto iter = first; iter != last; ++iter) {
        *iter = value;
    }
}
