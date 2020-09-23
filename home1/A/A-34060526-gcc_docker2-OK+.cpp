#include <iostream>
#include <string>

int main() {
    std::string password;
    getline(std::cin, password);
    int lower_case = 0;
    int upper_case = 0;
    int numbres = 0;
    int others = 0;
    int count_symbols = 0;
    for (const auto &i : password) {
        if (!(33 <= static_cast<int>(i) && static_cast<int>(i) <= 126)) {
            count_symbols = 0;
            break;
        }
        count_symbols++;
        if (islower(i)) {
            lower_case = 1;
        } else if (isupper(i)) {
            upper_case = 1;
        } else if (isdigit(i)) {
            numbres = 1;
        } else {
            others = 1;
        }
    }
    if (8 <= count_symbols && count_symbols <= 14
            && (lower_case + upper_case + numbres + others) >= 3) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }


    return 0;
}
