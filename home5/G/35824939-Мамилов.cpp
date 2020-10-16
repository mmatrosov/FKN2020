#include "tokenizer.h"
#include <algorithm>

class StatCallback : public CallbackBase {
private:
    size_t count = 0, maxLen = 0;
public:
    void OnToken(const char* token, size_t length) override {
        ++count;
        maxLen = std::max(length, maxLen);
    }

    size_t GetCount() {
        return count;
    }

    size_t GetMaxLen() {
        return maxLen;
    }
};

#include <iostream>
#include <memory>

int main() {
    std::string text;
    getline(std::cin, text);
    Tokenizer tokenizer;
    StatCallback* base = new StatCallback();
    tokenizer.Tokenize(text, base);
    std::cout << base->GetCount() << ' ' << base->GetMaxLen();
    delete base;
    return 0;
}