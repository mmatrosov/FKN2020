#include <iostream>
#include <map>

int main() {
    int x;
    std::map<int, bool> num_in_seq;
    while (std::cin >> x) {
        if (num_in_seq[x]) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        std::cout << "\n";
        num_in_seq[x] = true;
    }

    return 0;
}
