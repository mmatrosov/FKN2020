#include <iostream>
#include <string>

template <typename T>
void Print(const T &cont, const std::string &sep) {
    for (auto it = cont.begin(); it != cont.end(); ) {
        std::cout << *(it++);
        std::cout << (it == cont.end() ? "\n" : sep);
    }
}
