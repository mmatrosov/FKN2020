#include "c.h"
#include <deque>

signed main() {
    int n;
    std::cin >> n;
    std::deque<C> x(n);
    for (int i = 0; i < n; i++)
        x.pop_front();
}
