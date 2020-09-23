#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    for (size_t i = 0, n = v.size(); i != n; ++i) {
        v.push_back(v[i]);
    }
}
