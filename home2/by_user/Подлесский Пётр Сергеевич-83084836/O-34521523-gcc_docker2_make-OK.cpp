#include <iostream>
#include <string>

using namespace std;

template <typename T>
void Print(const T& container, string sep) {
    auto it = container.begin();
    cout << *(it++);
    while (it != container.end()) {
        cout << sep << *(it++);
    }
    cout << '\n';
}
