#include "c.h"
#include <iostream>

void foo(int n) {
  if (n == 0) {
    return;
  }
  C x;
  foo(n - 1);
}

int main() {
  int n;
  std::cin >> n;
  foo(n);
}