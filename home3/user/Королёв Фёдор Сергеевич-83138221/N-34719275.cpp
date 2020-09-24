#include "c.h"
#include <deque>

int main() {
    std::deque <C> a(2), b(1);
    a.pop_back();
    b.pop_front();
    a.pop_front();
    return 0;
}