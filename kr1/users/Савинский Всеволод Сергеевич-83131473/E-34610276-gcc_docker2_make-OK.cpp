#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int len = v.size();
    for (size_t i = 0; i < len; ++i) {
        v.push_back(v[i]);
    }
}
