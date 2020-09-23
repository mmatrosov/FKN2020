#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t length = v.size();
    for (size_t i = 0; i < length; ++i) {
        v.emplace_back(v[i]);
    }
}
