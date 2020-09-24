#include "c.h"
#include <iostream>

int main() {
  C x1;
  C x2(std::move(x1));
}