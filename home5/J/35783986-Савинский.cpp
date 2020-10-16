#include <cstddef>  // for size_t
#include <string>

class RangeError {};

size_t CountValues(const char* data, size_t size) {
    size_t rest = 0, count = 0;
    for (size_t i = 0; i < size;) {
        if (rest == 0) {
            if (i + sizeof(size_t) > size) {
                throw RangeError();
            }
            rest = *reinterpret_cast<const size_t*>(data + i);
            i += sizeof(size_t), ++count;
        } else {
            --rest, ++i;
        }
    }
    if (rest) {
        throw RangeError();
    }
    return count;
}
