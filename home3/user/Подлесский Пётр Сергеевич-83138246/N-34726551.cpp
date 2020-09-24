#include "c.h"

int main() {
    C* x1 = new C;
    C* x2 = new C;
    C* x3 = new C;
    delete(x2);
    delete(x3);
    delete(x1);
}
