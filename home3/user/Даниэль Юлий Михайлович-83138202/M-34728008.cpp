#include <utility>
#include "c.h"

int main() {
    C x = C(), y = C();
    x = y;
    x = std::move(y);
    return 0;
}
