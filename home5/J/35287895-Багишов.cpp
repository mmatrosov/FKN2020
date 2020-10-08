#include <cstddef>
#include <cstring>

class RangeError {};

size_t CountValues(char const* data, size_t size) {
    size_t pos = 0;
    size_t count = 0;
    while (true) {  //
        if (pos == size) {
            break;
        }
        if (pos + sizeof(size_t) > size) {
            throw RangeError();
        }
        ++count;
        size_t block_size;
        std::memcpy(reinterpret_cast<char*>(&block_size), data + pos, sizeof(size_t));
        // protect against overflow
        if (block_size >= size) {  //
            throw RangeError();
        }
        pos += block_size + sizeof(size_t);
    }
    return count;
}