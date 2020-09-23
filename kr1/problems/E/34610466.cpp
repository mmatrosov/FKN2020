#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        v.push_back(v[i]);
    }
}