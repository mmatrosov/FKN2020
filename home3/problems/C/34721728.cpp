#include <iostream>

template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (first == last)
        return last;
    Iter ans = first;
    Iter cur = ++first;
    while (cur != last) {
        if (*cur != *ans) {
            ans++;
            *ans = *cur;
        }
        cur++;
    }
    return ++ans;
}
