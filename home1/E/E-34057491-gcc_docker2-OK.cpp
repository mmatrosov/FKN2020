#include <iostream>
#include <string>

const int MAXPOW = 7;

int main() {
    int answer = 0;
    std::string text;
    std::getline(std::cin, text);

    for (int i = 0; i < text.size();) {
        answer++;
        int byte = static_cast<int>(text[i]);

        int num_ones = 0;
        for (int pow = MAXPOW; pow >= 0; --pow) {
            if ((byte | (1 << pow)) != byte) break;
            num_ones++;
        }

        i += std::max(1, num_ones);
    }

    std::cout << answer << std::endl;

    return 0;
}