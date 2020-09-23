#include "c.h"

int main() {
    C x;
    C y = C(std::move(x));
}
