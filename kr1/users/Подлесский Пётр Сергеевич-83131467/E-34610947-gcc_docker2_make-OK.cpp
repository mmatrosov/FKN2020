#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    size_t sz = v.size();
    for (size_t i = 0; i < sz; ++i) {
        v.push_back(v[i]);
    }
}
