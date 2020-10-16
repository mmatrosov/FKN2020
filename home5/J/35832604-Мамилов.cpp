#include <cstddef>  // for size_t
#include <iostream>

class RangeError {
};

size_t CountValues(const char * data, size_t size) {
    size_t count = 0;
    for (size_t i = 0; i != size; ++count) {
        const size_t stringLen = *(reinterpret_cast<const size_t*>(data + i));
        if (stringLen >= size)
            throw RangeError();
        i += sizeof(size_t) + stringLen;
        if (i > size)
            throw RangeError();
    }
    return count;
}