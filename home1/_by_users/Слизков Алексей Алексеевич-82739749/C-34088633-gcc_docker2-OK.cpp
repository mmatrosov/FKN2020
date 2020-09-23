#include <iostream>

using namespace std;

int main() {
    std::cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\tA\tB\tC\tD\tE\tF\n";
    for (unsigned char c = 32; c < 128; ++c) {
        if (c % 16 == 0)
            std::cout << char(c / 16 + '0') << '\t';
        std::cout << c << '\t';
        if (c % 16 == 15)
            std::cout << '\n';
    }
    return 0;
}
