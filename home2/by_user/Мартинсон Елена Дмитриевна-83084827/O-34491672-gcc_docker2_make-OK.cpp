#include <iostream>
#include <string>

template <typename T>
void Print(const T &a, const std::string& cut) {
    int i = 0;
    for (const auto& el : a) {
        if (i != 0) {
            std::cout << cut;
        }
        i = 1;
        std::cout << el;
    }
    std::cout << "\n";
}
