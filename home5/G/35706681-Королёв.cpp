#include "tokenizer.h"
#include <iostream>

class MyCallbackBase : public CallbackBase {
private:
    int counter, maxlength;
public:
    MyCallbackBase() {
        counter = 0;
        maxlength = 0;
    }
    virtual void OnToken(const char * token, size_t length) {
        ++counter;
        if (maxlength < length)
            maxlength = length;
    }
    int GetCounter() const {
        return counter;
    }
    int GetMaxLength() const {
        return maxlength;
    }
    virtual ~MyCallbackBase() {}
};

int main() {
    std::string s;
    getline(std::cin, s);
    Tokenizer t;
    MyCallbackBase* mcb = new MyCallbackBase();
    t.Tokenize(s, mcb);
    std::cout << mcb->GetCounter() << ' ' << mcb->GetMaxLength();
    delete mcb;
    return 0;
}