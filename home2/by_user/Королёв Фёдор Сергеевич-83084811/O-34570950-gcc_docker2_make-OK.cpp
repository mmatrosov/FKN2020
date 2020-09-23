#include <iostream>
#include <string>

template<typename Container>
void Print(const Container& args, const std::string& sep) {
    auto start = args.begin();
    auto fin = args.end();
    if (fin == start) {
        return;
    }
    std::cout << *start;
    ++start;
    for (; start != fin; ++start) {
        std::cout << sep << *start;
    }
}