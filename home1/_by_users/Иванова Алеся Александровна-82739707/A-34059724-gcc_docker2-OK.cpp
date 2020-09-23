#include <iostream>

bool check_password(const std::string& password) {
    if (password.size() < 8 || password.size() > 14)
        return 0;
    int cap_letter = 0;
    int low_letter = 0;
    int digit = 0;
    int symbol = 0;
    for (const int& c : password) {
        if (c < 33 || c > 126) {
            return 0;
        }
        if (isupper(c)) {
            cap_letter = 1;
        } else if (islower(c)) {
            low_letter = 1;
        } else if (isdigit(c)) {
            digit = 1;
        } else {
            symbol = 1;
        }
    }
    if (cap_letter + low_letter + digit + symbol >= 3) {
        return 1;
    }
    return 0;
}

signed main() {
    std::string password;
    getline(std::cin, password);
    if (check_password(password)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
