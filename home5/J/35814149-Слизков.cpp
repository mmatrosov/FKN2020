#include <cstddef>

class RangeError {};

size_t CountValues(const char* data, size_t size) {
    size_t result = 0;
    while (size != 0) {
        size_t sz;
        if (size < sizeof(size_t))
            throw RangeError();
        sz = *reinterpret_cast<const size_t*>(data);
        if (size < sizeof(size_t) + sz)
            throw RangeError();
        size -= sizeof(size_t) + sz, data += sizeof(size_t) + sz;
        ++result;
    }
    return result;
}
