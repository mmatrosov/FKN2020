#include <iostream>
#include <deque>
#include "c.h"

int main() {
    int n;
    std::cin >> n;
    std::deque<C> queue(n);
    for (int i = 0; i < n; ++i)
        queue.pop_back();
    return 0;
}