#include <cstddef>  // for size_t

class RangeError {
};

size_t CountValues(const char * data, size_t size) {
    size_t ans = 0;
    auto ts = sizeof(size_t);
    size_t i = 0;
    while (!(i == size)) {
        size_t block_size = 0, st = 1;
        for (size_t j = 0; j != ts; ++j) {
            if (i == size)
                throw RangeError();
            block_size += st * static_cast<size_t>(*(data + i));
            ++i;
            st *= 256;
        }
        for (size_t j = 0; j != block_size; ++j) {
            if (i == size)
                throw RangeError();
            ++i;
        }
        ++ans;
    }
    return ans;
}