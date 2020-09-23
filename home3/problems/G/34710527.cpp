template< class It, class T >
void fill_range(It first, It last, const T& value) {
    for (It it = first; it != last; it++)
        *it = value;
}
