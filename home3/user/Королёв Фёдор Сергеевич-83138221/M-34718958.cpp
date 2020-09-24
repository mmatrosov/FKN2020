#include "c.h"

int main() {
    C x, y;
    x = y;
    x = std::move(y);
    return 0;
}