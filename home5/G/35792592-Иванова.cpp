#include <iostream>
#include <string>
#include <memory>
#include "tokenizer.h"

class MyCallbackBase: public CallbackBase {
private:
    int cnt = 0;
    int max_len = 0;
public:
    void OnToken(const char * token, size_t length) override {
        ++cnt;
        if (length > max_len)
            max_len = length;
    }

    int GetCnt() const {
        return cnt;
    }

    int GetMaxLen() const {
        return max_len;
    }
};

signed main() {
    std::string str;
    getline(std::cin, str);
    Tokenizer tok;
    MyCallbackBase* my_base = new MyCallbackBase();
    tok.Tokenize(str, my_base);
    std::cout << (*my_base).GetCnt() << " " << (*my_base).GetMaxLen();
    delete my_base;
}
