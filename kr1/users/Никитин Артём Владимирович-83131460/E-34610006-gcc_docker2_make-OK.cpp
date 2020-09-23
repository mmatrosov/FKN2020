#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    int ourEnd = v.size();
    for (int i = 0; i < ourEnd; i++) {
        v.push_back(v[i]);
    }
}