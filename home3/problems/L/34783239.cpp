#include <iostream>
#include "c.h"

C f(C b) {
    return b;
}

int main() {
    f(C());

    return 0;
}
