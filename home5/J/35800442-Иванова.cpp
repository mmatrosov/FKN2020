#include <cstddef>  // for size_t
#include <exception>
#include <iostream>

class RangeError {
};

size_t CountValues(const char * data, size_t sz) {
    size_t cnt = 0;
    size_t ans = 0;
    while (cnt < sz) {
        size_t cur_len = 0;
        for (size_t i = 0; i < 8; ++i) {
            if (cnt + i >= sz)
                throw RangeError();
            cur_len |= (data[cnt + i] << (8 * i));
        }
        cnt += 8;
        if (cnt + cur_len > sz)
            throw RangeError();
        cnt += cur_len;
        ++ans;
    }
    return ans;
}