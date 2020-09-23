#include <vector>

template<typename T>
void Duplicate(std::vector<T>& v) {
    v.reserve(v.size() * 2);
    for (auto it = v.begin(), end = v.end(); it != end; ++it) {
        v.push_back(*it);
    }
}
