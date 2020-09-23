#include <iostream>
#include <string>

int main() {
     std::string s;
     getline(std::cin, s);
     uint64_t result = 0;
     for (size_t i = 0; i != s.size(); ++i) {
         uint64_t c = s[i];
         result |= (c & 0x7F) << (7 * i);
     }
     std::cout << result << "\n";
}

