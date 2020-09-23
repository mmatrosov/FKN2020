#include <iostream>

template <typename T, typename S>
void print(T const &container, S const &separator) {
    bool is_first = true;
    for (auto const &item : container) {
        if (is_first) {
            is_first = false;
        } else {
            std::cout << separator;
        }
        std::cout << item;
    }
    std::cout << '\n';
}

// Standard reminder that naming functions in PascalCase sucks
template <typename T, typename U> void Print(T const &a, U const &b) {
    print(a, b);
}
