#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int vs = v.size();
    for (int i = 0; i < vs; ++i) {
        v.push_back(v[i]);
    }
}