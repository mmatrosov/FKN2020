#include <cstddef>  // for size_t

class RangeError {};

size_t CountValues(const char* data, size_t size) {
    size_t now = 0;
    size_t ans = 0;
    while (now < size) {
        size_t now_size = static_cast<size_t>(*(data + now));
        for (size_t i = 0; i < now_size + 8; ++i) {
            if (size == now) {
                throw RangeError();
            }
            ++now;
        }
        ans += 1;
    }
    return ans;
}
