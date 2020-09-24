#include "c.h"

int main() {
    C x;
    C y;
    x = y;
    x = std::move(y);
}
