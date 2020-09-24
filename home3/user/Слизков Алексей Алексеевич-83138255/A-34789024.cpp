#include <iostream>

template<typename It, typename Pred>
bool any_of(It first, It last, Pred f) {
    for (It iter = first; iter != last; ++iter)
        if (f(*iter))
            return true;
    return false;
}
