#include <cstddef>
#include <exception>

class RangeError {};

size_t CountValues(const char *data, size_t size) {
    if (size == 0)
        return 0;
    size_t len_of_word = 0;
    for (int i = 0; i < 8; ++i) {
        if (size == 0) {
            RangeError problem;
            throw problem;
        }
        len_of_word += (static_cast<unsigned int>(*data) << (i * 8));
        ++data;
        --size;
    }
    while (len_of_word > 0) {
        if (size == 0) {
            RangeError problem;
            throw problem;
        }
        --size;
        ++data;
        len_of_word--;
    }
    return static_cast<size_t>(1) + CountValues(data, size);
}
