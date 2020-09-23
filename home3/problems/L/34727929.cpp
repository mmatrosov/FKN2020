#include <utility>
#include "c.h"

int main() {
    C x = C();
    C y = std::move(x);
    return 0;
}
