#include "c.h"

signed main() {
    C x;
    C y(std::move(x));
}