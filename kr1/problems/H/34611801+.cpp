#include <iostream>
#include <string>

int const kUsefulBitsPerByte = 7;

int main() {
    std::string encoded;
    std::getline(std::cin, encoded);
    int offset = 0;
    uint64_t value = 0;
    for (auto _byte : encoded) {
        auto const byte = static_cast<uint64_t>(_byte);
        auto const byte_value = byte & ((1 << kUsefulBitsPerByte) - 1);
        value += (byte_value << offset);  //
        offset += kUsefulBitsPerByte;
        if (byte == byte_value) {
            break;
        }
    }
    std::cout << value;
}