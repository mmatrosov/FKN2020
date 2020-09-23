#include <iostream>
#include <string>

template<typename T>
void Print(const T& elements, const std::string& split) {
    bool is_first = true;
    for (const auto& elem : elements) {
        if (!is_first)
            std::cout << split;
        is_first = false;
        std::cout << elem;
    }
    std::cout << "\n";
}
