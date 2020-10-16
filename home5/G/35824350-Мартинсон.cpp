#include <iostream>
#include <memory>
#include <string>

#include "tokenizer.h"

class AnotheCall : public CallbackBase {
private:
    int tokens = 0;
    size_t len = 0;

public:
    AnotheCall() {
        tokens = 0;
        len = 0;
    }
    void OnToken(const char* token, size_t length) override {
        tokens += 1;
        if (length > len) {
            len = length;
        }
    }
    void print() {
        std::cout << tokens << " " << len << "\n";
    }
    ~AnotheCall() {
    }
};

#include <memory>
#include <vector>

int main() {
    std::string s;
    getline(std::cin, s);

    Tokenizer tokenizer;
    AnotheCall a;
    // CallbackBase b;
    // std::vector<std::shared_ptr<CallbackBase>> c;
    // c.push_back(std::shared_ptr<AnotheCall>(new AnotheCall()));
    // tokenizer.Tokenize(s, &(*c[0]));
    tokenizer.Tokenize(s, &a);
    a.print();

    return 0;
}
