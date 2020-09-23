#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    auto const original_size = v.size();
    for (size_t pos = 0; pos < original_size; ++pos) {
        v.push_back(v[pos]);
    }
}