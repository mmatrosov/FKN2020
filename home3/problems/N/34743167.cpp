#include "c.h"

int main() {
    C * x = new C();
    C * y = new C();
    C * z = new C();
    delete y;
    delete z;
    delete x;
    return 0;
}
