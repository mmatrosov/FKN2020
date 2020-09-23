#include "c.h"

int main() {
    C x, y = std::move(x);
    return 0;
}