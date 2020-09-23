#include <iostream>
#include <set>

int main() {
    std::string word;
    bool is_letter_used[26];
    for (int i = 0; i < 26; i++)
        is_letter_used[i] = true;
    while (std::cin >> word) {
        for (char letter = 'a'; letter <= 'z'; letter++)
            if (word.find(letter) == -1)
                is_letter_used[static_cast<int>(letter - 'a')] = false;
    }
    for (int i = 0; i < 26; i++)
        if (is_letter_used[i])
            std::cout << static_cast<char>(static_cast<char>(i) + 'a');
}
