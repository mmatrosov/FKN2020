#include <iostream>
#include <string>

#include "tokenizer.h"

class TokenHandler : public CallbackBase {
public:
    int number = 0;
    size_t len = 0;
    TokenHandler() : number(0), len(0) {
    }
    void OnToken(const char* token, size_t length) override {
        len = std::max(length, len);
        ++number;
    }
};

int main() {
    std::string s;
    getline(std::cin, s);
    Tokenizer tokenizer;
    TokenHandler h;
    tokenizer.Tokenize(s, &h);
    std::cout << h.number << ' ' << h.len << '\n';
}