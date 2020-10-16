#include <algorithm>
#include <iostream>
#include <memory>

#include "tokenizer.h"

class CallbackDerived : public CallbackBase {
    int cnt = 0, maxlen = -1;

public:
    int getCnt() const {
        return cnt;
    }
    int getMaxlen() const {
        return maxlen;
    }

    void OnToken(const char* token, size_t length) override {
        ++cnt, maxlen = std::max<int>(maxlen, length);
    }
};

int main() {
    std::string s;
    getline(std::cin, s);
    Tokenizer A;
    CallbackDerived* callback = new CallbackDerived();
    A.Tokenize(s, callback);
    std::cout << callback->getCnt() << ' ' << callback->getMaxlen();
    delete callback;
    return 0;
}
