#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    for (auto it = v.begin(), end = v.end(); it != end; ++it) {
        v.push_back(*it);
    }
}
