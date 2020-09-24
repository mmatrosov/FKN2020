#include <algorithm>
#include <vector>
#include "c.h"

int main() {
    size_t n;
    std::cin >> n;
    std::vector<C*> data(n);
    for (auto &e : data)
        e = new C();
    for (int i = n - 1; i >= 0; --i)
        delete(data[i]);
}
