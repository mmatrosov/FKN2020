#include "c.h"

signed main() {
    C x;
    C y;
    x = y;
    x = std::move(y);
}
