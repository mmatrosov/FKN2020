#include "c.h"
#include <vector>

signed main() {
    int n;
    std::cin >> n;
    std::vector<C> x(n);
    for (int i = 0; i < n; i++)
        x.pop_back();
}