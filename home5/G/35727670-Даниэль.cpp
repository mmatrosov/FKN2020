#include <iostream>
#include <string>

#include "tokenizer.h"

class Callback : public CallbackBase {
    int num = 0;
    size_t mxLen = 0;

public:
    void OnToken(const char* token, size_t length) override {
        mxLen = std::max(mxLen, length);
        num++;
    }

    int GetNum() {
        return num;
    }

    int GetMxLen() {
        return mxLen;
    }

    ~Callback() {
    }
};

int main() {
    Callback* callback = new Callback();
    Tokenizer tokenizer = Tokenizer();

    std::string s;
    std::getline(std::cin, s);
    tokenizer.Tokenize(s, callback);

    std::cout << callback->GetNum() << ' ' << callback->GetMxLen() << std::endl;
    delete callback;
    return 0;
}
