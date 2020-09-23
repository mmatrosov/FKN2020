#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        v.push_back(v[i]);
    }
}