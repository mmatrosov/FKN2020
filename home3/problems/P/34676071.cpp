#include <iostream>
#include <vector>
#include "c.h"

int main() {
    int n;
    std::cin >> n;
    std::vector<C*> obj;
    for (int i = 0; i < n; ++i) {
        obj.push_back(new C);
    }
    for (int i = 0; i < n; ++i) {
        delete obj[i];
    }
}
