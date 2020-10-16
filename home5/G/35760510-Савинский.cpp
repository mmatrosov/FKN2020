#include <iostream>
#include <string>

#include "tokenizer.h"

class MyCallback : public CallbackBase {
   public:
    size_t count = 0, max_length = 0;

    void OnToken(const char *token, size_t length) {
        count += 1;
        max_length = std::max(max_length, length);
    }

    ~MyCallback() {
        std::cout << count << ' ' << max_length << '\n';
    }
};

int main() {
    std::string str;
    std::getline(std::cin, str);

    CallbackBase *callback = new MyCallback;
    Tokenizer tokenizer;

    tokenizer.Tokenize(str, callback);
    delete callback;
}
