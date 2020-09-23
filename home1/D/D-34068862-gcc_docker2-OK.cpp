#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

int main() {
    std::string keys;
    getline(std::cin, keys, '\n');
    int m = 0, l = 0, L = 0, w = 0;
    std::string line;
    while (getline(std::cin, line)) {
        l += 1;
        int line_size = line.size();
        L = std::max(L, line_size);
        m += line_size;
        std::stringstream x;
        x << line;
        std::string word;
        while (x >> word) {
            w += 1;
        }
    }
    m += l;

    std::stringstream x;
    x << keys;
    std::string word;
    std::map<std::string, bool> needness;

    while (x >> word) {
        needness[word] = true;
    }
    if (needness["-l"]) {
        std::cout << l << " ";
    }
    if (needness["-w"]) {
        std::cout << w << " ";
    }
    if (needness["-m"]) {
        std::cout << m << " ";
    }
    if (needness["-L"]) {
        std::cout << L << " ";
    }
    std::cout << "\n";

    return 0;
}
