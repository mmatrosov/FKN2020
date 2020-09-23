#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cin >> password;

    int length = password.size();
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, hasOther = false;

    const int minCode = 33;
    const int maxCode = 126;
    bool inRange = true;

    for (int i = 0; i < length; ++i) {
        if (minCode > static_cast<int>(password[i]) || static_cast<int>(password[i] > maxCode)) {
            inRange = false;
        }
        if (islower(password[i])) {
            hasLower = true;
            continue;
        }
        if (isupper(password[i])) {
            hasUpper = true;
            continue;
        }
        if (isdigit(password[i])) {
            hasDigit = true;
            continue;
        }
        hasOther = true;
    }

    int countTypes = static_cast<int>(hasLower) + static_cast<int>(hasUpper) +
        static_cast<int>(hasDigit) + static_cast<int>(hasOther);

    const int minLength = 8;
    const int maxLength = 14;

    if (inRange && (minLength <= length && length <= maxLength) && countTypes >= 3) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}