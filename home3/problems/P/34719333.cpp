#include "c.h"
#include <deque>

int main() {
    int n;
    std::cin >> n;
    std::deque <C> a(n);
    while (n) {
        --n;
        a.pop_front();
    }
    return 0;
}