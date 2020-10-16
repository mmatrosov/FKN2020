#include <iostream>
#include <string>

#include "tokenizer.h"

class CallbackDerived : public CallbackBase {
private:
    size_t maxlen = 0;
    size_t tokens_am = 0;

public:
    void OnToken(const char* token, size_t length) override {
        maxlen = std::max(maxlen, length);
        tokens_am++;
    }

    size_t Get_maxlen() {
        return maxlen;
    }

    size_t Get_tokens_am() {
        return tokens_am;
    }

    ~CallbackDerived() {
    }
};

int main() {
    std::string s;
    std::getline(std::cin, s);
    Tokenizer tok;
    CallbackDerived* cb = new CallbackDerived;
    tok.Tokenize(s, cb);
    std::cout << cb->Get_tokens_am() << ' ' << cb->Get_maxlen() << '\n';
    delete cb;
}