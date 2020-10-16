#include <cstddef>

class RangeError {};

size_t CountValues(const char* data, size_t size) {
    size_t ans = 0;
    for (size_t i = 0; i < size;) {
        if (i + sizeof(size_t) > size)
            throw RangeError();
        size_t len = *reinterpret_cast<const size_t*>(data + i);
        i += sizeof(size_t);
        if (i + len > size)
            throw RangeError();
        i += len;
        ans++;
    }
    return ans;
}