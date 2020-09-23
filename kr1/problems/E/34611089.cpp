#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    auto size = v.size();
    for (auto it = 0; it < size; ++it) {
        v.push_back(v[it]);
    }
}
