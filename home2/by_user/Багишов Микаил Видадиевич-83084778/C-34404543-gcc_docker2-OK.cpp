#include <algorithm>
#include <array>
#include <iostream>
#include <string>

size_t const ALPHABET_SIZE = 26;
char const ALPHABET_BASE = 'a';

int main() {
  std::array<bool, ALPHABET_SIZE> bad;
  std::fill(bad.begin(), bad.end(), false);

  std::string word;
  while (std::cin >> word) {
    std::array<bool, ALPHABET_SIZE> present;
    std::fill(present.begin(), present.end(), false);
    for (char const ch : word) {
      present[ch - ALPHABET_BASE] = true;
    }
    for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
      if (!present[i]) {
        bad[i] = true;
      }
    }
  }

  for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
    if (bad[i]) {
      continue;
    }
    std::cout << static_cast<char>(ALPHABET_BASE + i);
  }
  std::cout << std::endl;
}