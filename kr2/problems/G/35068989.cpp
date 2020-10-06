#include <cstddef>

template <typename It1, typename It2>
size_t count_subsegments(It2 data_first, It2 data_last, It1 pat_first, It1 pat_last) {
    size_t res = 0;
    for (It2 begin = data_first; begin != data_last; ++begin) {
        It2 cur = begin;
        bool has_match = true;
        for (It1 pat_item = pat_first; pat_item != pat_last; ++pat_item) {
            if (cur == data_last || *cur != *pat_item) {
                has_match = false;
                break;
            }
            ++cur;
        }
        if (has_match) {
            ++res;
        }
    }

    return res;
}