#include <cmath>
#include <iostream>
#include <memory>
#include <string>

#include "tokenizer.h"

struct Callback : CallbackBase {
    size_t cnt_tokens = 0;
    size_t max_token = 0;

    void OnToken(const char*, size_t length) override {
        ++cnt_tokens;
        max_token = std::max(max_token, length);
    }
};

int main() {
    std::string input;
    std::getline(std::cin, input);
    Tokenizer tokenizer;
    Callback cb;
    tokenizer.Tokenize(input, &cb);

    std::cout << cb.cnt_tokens << " " << cb.max_token << "\n";
}