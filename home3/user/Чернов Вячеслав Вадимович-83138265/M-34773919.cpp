#include "c.h"
#include <iostream>

int main() {
  C x1;
  C x2;
  x1 = x2;
  x1 = std::move(x2);
}
