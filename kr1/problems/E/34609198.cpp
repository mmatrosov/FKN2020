#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
        v.push_back(v[i]);
    }
}